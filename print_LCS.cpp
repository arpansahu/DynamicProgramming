#include<iostream>
#include <unordered_map>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
int lookup[20][20];

string  LCS(string X,string Y,int m,int n){
    if(m == 0 || n == 0) return string("");
    if(X[m - 1] == Y[n - 1]) return LCS(X,Y,m-1,n-1) + X[m-1];

    if(lookup[m-1][n] > lookup[m][n-1]) return LCS(X,Y,m-1,n);
    else return  LCS(X,Y,m,n-1);


}

void LCSLength(string X,string Y,int m,int n){
    for (int i = 1; i <= m ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(X[i - 1] == Y[j -1]) lookup[i][j] = lookup[i-1][j-1] + 1;
            else lookup[i][j] = max(lookup[i][j-1],lookup[i-1][j]);
        }
    }
}


int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    int m  = X.length(), n = Y.length();
    LCSLength(X,Y,m,n);
    cout<<LCS(X,Y,m,n);
    return 0;
}