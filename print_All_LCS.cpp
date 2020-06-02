#include<iostream>
#include <unordered_map>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
int lookup[20][20];

vector <string>  LCS(string X,string Y,int m,int n){
    if(m == 0 || n == 0) {
        vector<string> v(1);
        return v;
    }
    if(X[m - 1] == Y[n - 1]){
        vector<string> lcs = LCS(X,Y,m-1,n-1);
        for(auto & str : lcs) str.push_back(X[m-1]);
        return lcs;
    }

    if(lookup[m-1][n] > lookup[m][n-1]) return LCS(X,Y,m-1,n);
    if(lookup[m][n-1] > lookup[m-1][n]) return LCS(X,Y,m,n-1);

    vector<string> top = LCS(X,Y,m-1,n);
    vector<string> left = LCS(X,Y,m,n-1);

    top.insert(top.end(),left.begin(),left.end());
    return top;

}

void LCSLength(string X,string Y,int m,int n){
    for (int i = 1; i <= m ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(X[i - 1] == Y[j -1]) lookup[i][j] = lookup[i-1][j-1] + 1;
            else lookup[i][j] = max(lookup[i][j-1],lookup[i-1][j]);
        }
    }
}

set<string> LCS(string X,string Y){
    int m = X.length() , n = Y.length();
    int lookup[m][n];
    LCSLength(X,Y,m,n);
    vector<string> v = LCS(X,Y,m,n);
    set<string> lcs(make_move_iterator(v.begin()),make_move_iterator(v.end()));
    return lcs;
}
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    set<string> lcs = LCS(X, Y);
    for (string str : lcs)  cout << str << endl;
    return 0;
}