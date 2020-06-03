#include<iostream>
#include <unordered_map>
#include <cstring>

using namespace std;
int max(int a,int b,int c){
    return (max(a,max(b,c)));
}
int LCSrecusrive(string X,string Y,string Z,int m ,int n,int o){
    if(m == 0 || n == 0 || o ==0 ) return 0;
    if(X[m-1] == Y[n-1] && Y[n-1] == Z[o-1]) return LCSrecusrive(X,Y,Z,m-1,n-1,o-1) + 1;
    return max(LCSrecusrive(X,Y,Z,m-1,n,o),LCSrecusrive(X,Y,Z,m,n - 1,o),LCSrecusrive(X,Y,Z,m,n,o-1));
}

int LCSMemoization(string X,string Y,string Z,int m,int n,int o,auto  & lookup){
    if (m == 0 || n == 0 || o ==0) return 0;
    string key = to_string(m) + "|" + to_string(n) +  "|" + to_string(o);
    if(lookup.find(key)  == lookup.end()){
        if(X[m-1] == Y[n-1]) lookup[key] = LCSMemoization(X,Y,Z,m-1,n-1,o-1,lookup) + 1;
        else  lookup[key] = max(LCSMemoization(X,Y,Z,m-1,n,o,lookup),LCSMemoization(X,Y,Z,m,n-1,o,lookup),LCSMemoization(X,Y,Z,m,n,o-1,lookup));
    }
    return lookup[key];
}
int LCSTabulization(string X,string Y,string Z){
    int m = X.length(), n = Y.length(), o = Z.length();

    int lookup[m + 1][n + 1][o + 1];

    memset(lookup, 0, sizeof lookup);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= o; k++)
            {
                if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1])   lookup[i][j][k] = lookup[i - 1][j - 1][k - 1] + 1;
                else    lookup[i][j][k] = max(lookup[i - 1][j][k],lookup[i][j - 1][k],lookup[i][j][k - 1]);
            }
        }
    }
    return lookup[m][n][o];
}

int main(){
    string X = "ABCBDAB", Y = "BDCABA", Z = "BADACB";
    cout << LCSrecusrive(X,Y,Z,X.length(),Y.length(),Z.length())<<"\n";
    unordered_map<string,int> lookup;
    cout<<LCSMemoization(X,Y,Z,X.length(),Y.length(),Z.length(),lookup)<<"\n";
    cout<<LCSTabulization(X,Y,Z);
    return 0;
}