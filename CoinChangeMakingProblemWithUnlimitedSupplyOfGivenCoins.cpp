#include<iostream>
#include <climits>

using namespace std;

int findMinCoinsrecusrsive(int S[],int n,int totalMoney){
    if(totalMoney == 0) return  0;
    if(totalMoney < 0) return INT_MAX;

    int coins = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int res = findMinCoinsrecusrsive(S,n,totalMoney - S[i]);
        if(res != INT_MAX) coins = min(coins,res+1);
    }

    return coins;
}
int findMinCoinsTabulisation(int S[],int n,int totalMoney) {
    int lookup[totalMoney + 1];
    lookup[0] = 0;
    for (int i = 0; i <= n; ++i) {
        lookup[i] = INT_MAX;
        int res = INT_MAX;

        for (int c = 0; c < n; ++c) {
            if (i - S[c] >= 0) res = lookup[i - S[c]];
            if (res != INT_MAX) lookup[i] = min(lookup[i], res + 1);
        }
    }
    return lookup[totalMoney];
}
int main()
{
    int S[] = { 1, 2, 3, 4 };
    int n = sizeof(S) / sizeof(S[0]);
    int totalMoney = 15;
    cout << "Minimum number of coins required to get desired change is " << findMinCoinsrecusrsive(S, n, totalMoney)<<endl;
    cout << "Minimum number of coins required to get desired change is " << findMinCoinsrecusrsive(S, n, totalMoney);


    return 0;
}