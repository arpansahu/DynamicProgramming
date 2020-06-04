#include<iostream>
#include <unordered_map>
using namespace std;

int lengthOFShortestCommonSupersequence(string X,string Y,auto & lookup,int m ,int n){
    if(m == 0 || n == 0) return 0;

    string key  = to_string(m) + "|" + to_string(n);
    if(lookup.find(key) == lookup.end()){
        if(X[m - 1] == Y[n - 1]) lookup[key] = lengthOFShortestCommonSupersequence(X,Y,lookup,m-1,n-1) + 1;
        else lookup[key] = max(lengthOFShortestCommonSupersequence(X,Y,lookup,m-1,n) ,lengthOFShortestCommonSupersequence(X,Y,lookup,m,n - 1) );
    }
    return lookup[key];
}

int lengthOFShortestCommonSupersequence(string X, string Y)
{
    int m = X.length(), n = Y.length();
    int lookup[m + 1][n + 1];

    for (int i = 0; i <= m; i++)    lookup[i][0] = 0;
    for (int j = 0; j <= n; j++)    lookup[0][j] = 0;

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (X[i - 1] == Y[j - 1])   lookup[i][j] = lookup[i - 1][j - 1] + 1;
            else    lookup[i][j] = max(lookup[i - 1][j],lookup[i][j - 1]);
        }
    }

    return lookup[m][n];
}


int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    int m = X.length(), n = Y.length();
    cout <<m + n - lengthOFShortestCommonSupersequence(X,Y)<<"\n";
    unordered_map<string,int> lookup;
    cout<< m + n - lengthOFShortestCommonSupersequence(X,Y,lookup,m,n);
    return 0;
}