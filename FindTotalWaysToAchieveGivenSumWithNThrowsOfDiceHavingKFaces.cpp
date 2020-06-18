#include <iostream>
using  namespace std;
#include <algorithm>
#include <unordered_map>
#include <cstring>
int numberOFwaysToAchieveKSumRecursive(int n,int k,int sum){
    if (n == 0) return (sum == 0);
    if(sum < 0 || k * n < sum || n > sum) return 0 ;
    int res = 0;
    for (int i = 1; i <= k; ++i) res += numberOFwaysToAchieveKSumRecursive(n-1,k,sum - i);
    return res;
}

unordered_map <string,int > lookup;
int numberOFwaysToAchieveKSumMemoization(int n,int k,int sum){
    if (n == 0) return (sum == 0);
    if(sum < 0 || k * n < sum || n > sum) return 0 ;

    string key = to_string(n) + "|" + to_string(k) + "|" + to_string(sum);
    if(lookup.find(key) == lookup.end()){

        int res = 0;
        for (int i = 1; i <= k; ++i) res += numberOFwaysToAchieveKSumMemoization(n-1,k,sum - i);
        lookup[key] = res;
    }

    return lookup[key];
}

int numberOFwaysToAchieveKSumTabulisation(int f, int d, int s)
{
    long lookup[d + 1][s + 1];
    memset(lookup, 0, sizeof lookup);

    lookup[0][0] = 1;

    for (int i = 1; i <= d; i++)
    {
        for (int j = i; j <= s; j++)
        {
            lookup[i][j] = lookup[i][j - 1] + lookup[i - 1][j - 1];
            if (j - f - 1 >= 0) lookup[i][j] -= lookup[i - 1][j - f - 1];
        }
    }

    return lookup[d][s];
}

int main()
{
    int n =2;
    int k = 6;
    int sum =10;

    cout <<numberOFwaysToAchieveKSumRecursive(n,k,sum)<<endl;
    cout <<numberOFwaysToAchieveKSumMemoization(n,k,sum)<<endl;
    cout <<numberOFwaysToAchieveKSumTabulisation(k,n,sum)<<endl;

    return 0;
}