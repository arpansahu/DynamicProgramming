#include<iostream>
#include <unordered_map>
using namespace std;

int LCSrecusrive(string X,string Y,int m ,int n){
    if(m == 0 || n == 0) return 0;
    if(X[m-1] == Y[n-1]) return LCSrecusrive(X,Y,m-1,n-1) + 1;
    return max(LCSrecusrive(X,Y,m,n-1),LCSrecusrive(X,Y,m - 1,n));
}
int LCSMemoization(string X,string Y,int m,int n,auto  & lookup){
    if (m == 0 || n == 0) return 0;
    string key = to_string(m) + "|" + to_string(n);
    if(lookup.find(key)  == lookup.end()){
        if(X[m-1] == Y[n-1]) lookup[key] = LCSMemoization(X,Y,m-1,n-1,lookup) + 1;
        else  lookup[key] = max(LCSMemoization(X,Y,m-1,n,lookup),LCSMemoization(X,Y,m,n-1,lookup));
    }
    return lookup[key];
}
int LCSTabulization(string X,string Y){
    int m = X.length(),n = Y.length();
    int  arr[m + 1][n + 1];

    for (int i = 0; i <= m  ; ++i) arr[i][0] = 0;
    for (int j = 0; j <= n ; ++j) arr[0][j] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(X[i - 1] == Y[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
            else arr[i][j] = max(arr[i - 1][j],arr[i][j-1]);
        }
    }
    return  arr[m][n];
}

int main(){
    string X = "XMJYAUZ", Y = "MZJAWXU";
    cout << LCSrecusrive(X,Y,X.length(),Y.length())<<"\n";
    unordered_map<string,int> lookup;
    cout<<LCSMemoization(X,Y,X.length(),Y.length(),lookup)<<"\n";
    cout<<LCSTabulization(X,Y);
    return 0;
}