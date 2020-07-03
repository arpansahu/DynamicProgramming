#include <iostream>
#include<vector>
#define M 5
#define N 4
using namespace std;

int isValid(int i ,int x,int y){
    return i < M && x >= 0 && x < N  && y >= 0 && y < N;
}

int maxCoins(int mat[M][N],int i,int x,int y){
    if(!isValid(i,x,y)){
        return INT_MIN;
    }

    if(i == M-1){
        if(x == 0 && y == N-1) return (x == y) ? mat[i][x] : mat[i][x] + mat[i][y];
    }

    int coins = INT_MIN;

    coins = max(coins, maxCoins(mat, i + 1, x - 1, y - 1));
    coins = max(coins, maxCoins(mat, i + 1, x - 1, y));
    coins = max(coins, maxCoins(mat, i + 1, x - 1, y + 1));

    coins = max(coins, maxCoins(mat, i + 1, x, y - 1));
    coins = max(coins, maxCoins(mat, i + 1, x, y));
    coins = max(coins, maxCoins(mat, i + 1, x, y + 1));

    coins = max(coins, maxCoins(mat, i + 1, x + 1, y - 1));
    coins = max(coins, maxCoins(mat, i + 1, x + 1, y));
    coins = max(coins, maxCoins(mat, i + 1, x + 1, y + 1));
    
    if(x == y) return mat[i][x] + coins;
    else return (mat[i][x] + mat[i][y]) + coins;
}

int main(void)
{
    int mat[][N] =
            {
                    { 0, 2, 4, 1 },
                    { 4, 8, 3, 7 },
                    { 2, 3, 6, 2 },
                    { 9, 7, 8, 3 },
                    { 1, 5, 9, 4 }
            };

    printf("The maximum coins collected is %d",maxCoins(mat, 0, 0, N - 1));
    return 0;
}