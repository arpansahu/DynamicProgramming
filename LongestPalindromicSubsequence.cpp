#include<iostream>
#include <set>
#include <algorithm>

using namespace std;
int lookup[20][20];

string  PalindromicLCS(string X,string Y,int m,int n){
    if(m == 0 || n == 0) return string("");
    if(X[m - 1] == Y[n - 1]) return PalindromicLCS(X,Y,m-1,n-1) + X[m-1];
    if(lookup[m-1][n] > lookup[m][n-1]) return PalindromicLCS(X,Y,m-1,n);
    else return  PalindromicLCS(X,Y,m,n-1);
}

int lengthOFLCSubstring(string X,string Y,int n){
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(X[i - 1] == Y[j - 1]) lookup[i][j] = lookup[i - 1][j - 1] + 1;
            else lookup[i][j] = max(lookup[i][j - 1],lookup[i - 1][j]);
        }
    }
    return lookup[n][n];
}

int main()
{
    string X = "ABBDCACB";
    string Y = X;
    reverse(Y.begin(),Y.end());
    int m = X.length(),n = Y.length();
    cout<< lengthOFLCSubstring(X,Y,m)<<endl;
    cout<<PalindromicLCS(X,Y,m,n);
    return 0;
}