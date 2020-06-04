#include<iostream>

using namespace std;
int lookup[20][20];

string  printShortestCommonSupersequence(string X, string Y,int m ,int n){
    if (m == 0) return Y.substr(0, n);
    else if (n == 0)    return X.substr(0, m);


    if (X[m - 1] == Y[n - 1])   return printShortestCommonSupersequence(X, Y, m - 1, n - 1) + X[m - 1];
    else
    {
        if (lookup[m - 1][n] < lookup[m][n - 1])    return printShortestCommonSupersequence(X, Y, m - 1, n) + X[m-1];
        else    return printShortestCommonSupersequence(X, Y, m, n - 1) + Y[n-1];
    }
}
void lengthOFShortestCommonSupersequence(string X, string Y,int m ,int n)
{
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (X[i - 1] == Y[j - 1])   lookup[i][j] = lookup[i - 1][j - 1] + 1;
            else    lookup[i][j] = min(lookup[i - 1][j] + 1,lookup[i][j - 1] + 1);
        }
    }
}


int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    lengthOFShortestCommonSupersequence(X,Y,X.length(),Y.length());
    cout<<printShortestCommonSupersequence(X,Y,X.length(),Y.length());
    return 0;
}