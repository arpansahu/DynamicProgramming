#include<iostream>
#include <climits>
using namespace std;
#define MAX 10

int lookup[MAX][MAX];

int MatrixChainMultiplicationRecursion(int dims[],int i,int j){
    if(j <= i + 1) return 0;
    int min = INT_MAX;

    for (int k =  i + 1; k <= j - 1  ; ++k) {
        int cost  = MatrixChainMultiplicationRecursion(dims,i,k);
        cost  = cost + MatrixChainMultiplicationRecursion(dims,k,j);
        cost += dims[i] * dims[k] * dims[j];

        if(cost < min ) min = cost;
    }
    return min;
}
int MatrixChainMultiplicationMemoization(int dims[],int i ,int j){
    if(j <= i + 1) return 0;
    int min  = INT_MAX;

    if(lookup[i][j] == 0){
        for (int k =  i + 1; k <= j - 1 ; ++k) {
            int cost  = MatrixChainMultiplicationMemoization(dims,i,k);
            cost += MatrixChainMultiplicationMemoization(dims,k,j);
            cost += dims[i] * dims[k] * dims[j];

            if(cost < min) min = cost;
        }
        lookup[i][j] = min;
    }
    return lookup[i][j];
}

int MatrixChainMultiplicationTabulisation(int dims[],int n){
    int lookup1[n + 1][n + 1];

    for (int i = 1; i <= n  ; ++i) lookup1[i][i] = 0;

    for (int len = 2; len <=  n ; ++len) {
        for (int i = 1; i < n - len + 1 ; ++i) {
            int j = i + len - 1;
            lookup1 [i][j] = INT_MAX;

            for (int k = i; k <= j - 1 && j < n ; ++k) {
                int cost = lookup1[i][k] + lookup1[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if(cost < lookup1[i][j]) lookup1[i][j] = cost;
            }
        }
    }
    /*
     * for (int l = 0; l < n +1; ++l) {
        for (int i = 0; i < n+1 ; ++i) {
            cout << lookup1[l][i] << " ";
        }cout<<endl;
    }
     */
    return lookup1[1][n - 1];
}
int main()
{
    int dims[] = { 10, 30, 5, 60 };
    int n = sizeof(dims) / sizeof(dims[0]);

    cout << "Minimum cost is " << MatrixChainMultiplicationRecursion(dims, 0, n - 1) <<"\n";

    cout << "Minimum cost is " << MatrixChainMultiplicationMemoization(dims, 0, n - 1)<<"\n";

    cout << "Minimum cost is " << MatrixChainMultiplicationTabulisation(dims,  n );

    return 0;
}