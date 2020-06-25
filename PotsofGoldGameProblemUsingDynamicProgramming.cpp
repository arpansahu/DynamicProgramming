#include <iostream>
#include <unordered_map>
using namespace std;


int optimalStrategyRecursive(int *coins, int i, int j){
    if (i == j)return coins[i];
    if (i + 1 == j)return max(coins[i], coins[j]);

    int start = coins[i] + min(optimalStrategyRecursive(coins, i + 2, j), optimalStrategyRecursive(coins, i + 1, j - 1));
    int end = coins[j] + min(optimalStrategyRecursive(coins, i + 1, j - 1), optimalStrategyRecursive(coins, i, j - 2));

    return max(start, end);
}

unordered_map<string,int> lookup;

int optimalStrategyMemoization(int coins[],int i,int j){
    if (i == j)return coins[i];
    if (i + 1 == j)return max(coins[i], coins[j]);

    string key = to_string(i) + "|" + to_string(j);

    if(lookup.find(key) == lookup.end()){
        int start = coins[i] + min(optimalStrategyRecursive(coins, i + 2, j), optimalStrategyRecursive(coins, i + 1, j - 1));
        int end = coins[j] + min(optimalStrategyRecursive(coins, i + 1, j - 1), optimalStrategyRecursive(coins, i, j - 2));

        lookup[key] = max(start, end);
    }
    return lookup[key] ;
}

int calculate(int **lookup,int i,int j){
    if(i <= j) return lookup[i][j];
    return 0;
}

int optimalStrategyTabulisation(int coins[],int n){
    if(n == 1) return coins[0];
    if(n==2) return max(coins[0],coins[1]);

    int ** lookup = new int*[n];
    for (int i = 0; i < n ; ++i) lookup[i] = new int[n];

    for (int iteration = 0; iteration < n; iteration++)
    {
        for (int i = 0, j = iteration; j < n; i++, j++)
        {

            int start = coins[i] + min(calculate(lookup, i + 2, j),calculate(lookup, i + 1, j - 1));
            int end = coins[j] + min(calculate(lookup, i + 1, j - 1),calculate(lookup, i, j - 2));
            lookup[i][j] = max(start, end);
        }
    }
    int result = lookup[0][n-1];
    for (int i = 0; i < n; ++i) delete[] lookup[i];

    return result;
}
int main()
{
    int coin[] = { 6, 1, 4, 9, 8, 5 };
    int n = sizeof(coin) / sizeof(coin[0]);
    cout << "Maximum coins collected by player is " << optimalStrategyRecursive(coin, 0, n - 1)<<endl;
    cout << "Maximum coins collected by player is " << optimalStrategyMemoization(coin, 0, n - 1)<<endl;
    cout << "Maximum coins collected by player is " << optimalStrategyTabulisation(coin, n )<<endl;
    return 0;
}