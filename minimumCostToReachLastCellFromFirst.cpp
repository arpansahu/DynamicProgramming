#include<iostream>
#include <climits>
using namespace std;
#define M 5
#define  N 5


int findMinCost(int cost[M][N], int m, int n)
{
    if (n == 0 || m == 0) return INT_MAX;
    if (m == 1 && n == 1) return cost[0][0];
    return min (findMinCost(cost, m - 1, n), findMinCost(cost, m, n - 1))   + cost[m - 1][n - 1];
}

int findMinCostTabulisation(int mat[M][N]){
    int lookup[M][N];

    for (int i = 0; i < M ; ++i) {
        for (int j = 0; j < N; ++j) {
            lookup[i][j] = mat[i][j];
            if(i == 0 && j > 0) lookup[0][j] += lookup[i][j-1];
            if(i > 0 && j == 0) lookup[i][0] += lookup[i-1][j];
            else if(i > 0 && j > 0) lookup[i][j] += min(lookup[i-1][j],lookup[i][j-1]);
        }
    }
    return lookup[M-1][N-1];
}
int main()
{
    int cost[M][N] =
            {
                    { 4, 7, 8, 6, 4 },
                    { 6, 7, 3, 9, 2 },
                    { 3, 8, 1, 2, 4 },
                    { 7, 1, 7, 3, 7 },
                    { 2, 9, 8, 9, 3 }
            };

    cout << "The minimum cost is " << findMinCost(cost, M, N)<<endl;
    cout << "The minimum cost is " << findMinCostTabulisation(cost);
    return 0;
}