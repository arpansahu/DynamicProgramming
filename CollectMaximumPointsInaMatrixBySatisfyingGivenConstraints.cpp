#include<iostream>
#include <cstring>
using namespace std;
#define M 5
#define N 5

bool isSafe (int mat[M][N],int x,int y){

    if(x < 0 || x >= M || y < 0 || y >= N || mat[x][y] == -1) return false ;
    return true ;

}

int findMaximumRecursive(int arr[M][N],int x,int y){
    if(!isSafe(arr,x,y)) return 0;
    if(x % 2 == 0) return arr[x][y] +  max(findMaximumRecursive(arr,x,y +1) , findMaximumRecursive(arr,x+1,y));
    else return arr[x][y] + max(findMaximumRecursive(arr,x,y-1),findMaximumRecursive(arr,x+1,y));
}

int findMaximumIterative(int arr[M][N])
{

    int lookup[M + 2][N + 2];
    memset(lookup, 0, sizeof lookup);
    int res = lookup[1][1];

    for (int i = 1; i<= M; i++)
    {
        if (i & 1)
            for (int j = 1; j <= N; j++)
                {
                    if (arr[i - 1][j - 1] != -1)  lookup[i][j] = arr[i - 1][j - 1] + max(lookup[i][j - 1], lookup[i - 1][j]);
                    if(res < lookup[i][j]) res = lookup[i][j];
                }
        else
            for (int j = N; j >= 1; j--)   {
                if (arr[i - 1][j - 1] != -1) lookup[i][j] = arr[i - 1][j - 1] + max(lookup[i][j + 1], lookup[i - 1][j]);
                if(res < lookup[i][j]) res = lookup[i][j];
            }
    }


  /*
   *   for (int i = 0; i <= M+1; i++)
    {
        for (int j = 0; j <= N+1; j++)
            cout << lookup[i][j] << " ";
        cout << endl;
    }
   */

    return res;
}

int main()
{
    int mat[M][N] =
            {
                    {  1,  1, -1,  1,  1 },
                    {  1,  0,  0, -1,  1 },
                    {  1,  1,  1,  1, -1 },
                    { -1, -1,  1,  1,  1 },
                    {  1,  1, -1, -1,  1 }
            };

    cout << "Maximum value collected is " << findMaximumRecursive(mat, 0, 0)<<endl;
    cout << "Maximum value collected is " <<findMaximumIterative(mat);
    return 0;
}