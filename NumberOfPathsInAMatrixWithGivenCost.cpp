#include<iostream>
#include <unordered_map>
#include <climits>
using namespace std;
#define M 4
#define  N 5
unordered_map<string,int> lookup;

int countPathsRecursion(int mat[][N],int m,int n,int cost){
    if(cost < 0 ) return 0;
    if(m == 0 && n ==0){
        if(cost - mat[m][n] ==  0) return 1;
        else return 0;
    }
    if(m == 0 && n > 0) return countPathsRecursion(mat,0,n-1,cost - mat[m][n]);
    if(n == 0 && m > 0) return countPathsRecursion(mat,m-1,0,cost - mat[m][n]);
    return countPathsRecursion(mat,m-1,n,cost-mat[m][n]) + countPathsRecursion(mat,m,n-1,cost-mat[m][n]);
}

int countPathsMemoization(int mat[][N], int m, int n, int cost)
{   string key = to_string(m) + "|" + to_string(n) + "|" +to_string(cost);
    if(cost < 0 ) return 0;
    if(m == 0  && n == 0){
        if(mat[0][0] - cost == 0) return 1;
        else return 0;
    }
    if(lookup.find(key) == lookup.end()){
        if(m == 0) lookup[key] = countPathsMemoization(mat,0,n -1,cost - mat[m][n]);
        if(n == 0) lookup[key] =  countPathsMemoization(mat,m-1,n,cost - mat[m][n]);
        else lookup[key] = countPathsMemoization(mat,m-1,n,cost - mat[m][n]) + countPathsMemoization(mat,m,n-1,cost - mat[m][n]);
    }
    return lookup[key];
}
int main()
{
    int mat[M][N] =
            {
                    { 4, 7, 1, 6 },
                    { 5, 7, 3, 9 },
                    { 3, 2, 1, 2 },
                    { 7, 1, 6, 3 }
            };

    int cost = 25;
    cout << "Total paths with cost " << cost << " are " <<countPathsRecursion(mat, M-1, N-1, cost)<<endl;
    cout << "Total paths with cost " << cost << " are " <<countPathsMemoization(mat, M-1, N-1, cost)<<endl;
    return 0;
}