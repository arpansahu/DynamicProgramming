#include<iostream>

#define  M 8
#define  N 6

using namespace std;

int findLargestSquare(int mat[M][N]){
    int lookup[M][N];
    int max = 0;

    for (int i = 0; i < M ; ++i) {
        for (int j = 0; j < N; ++j) {

            lookup[i][j] = mat[i][j];

            if(i && j && mat[i][j]) lookup[i][j] = min(min(lookup[i][j-1],lookup[i-1][j]),lookup[i-1][j-1]) + 1;

            if(max < lookup[i][j]) max = lookup[i][j];
        }
    }

    /*
     * 
     for (int k = 0; k < M; ++k) {
        for (int i = 0; i < N; ++i) {
            cout<<lookup[k][i]<<" ";
        }cout<<endl;
    }
     */
    return max;
}


int main()
{
    int mat[M][N] =
            {
                    { 0, 0, 1, 0, 1, 1 },
                    { 0, 1, 1, 1, 0, 0 },
                    { 0, 0, 1, 1, 1, 1 },
                    { 1, 1, 0, 1, 1, 1 },
                    { 1, 1, 1, 1, 1, 1 },
                    { 1, 1, 0, 1, 1, 1 },
                    { 1, 0, 1, 1, 1, 1 },
                    { 1, 1, 1, 0, 1, 1 }
            };

    cout <<findLargestSquare(mat)<<"\n";

    return 0;
}