#include<iostream>
#include <vector>
#include <set>
using namespace std;
int lookup[20][20];

vector<string>  printAllShortestCommonSupersequence(string X, string Y,int m ,int n){

    if (m == 0)
    {
        vector<string> v;
        v.push_back(Y.substr(0, n));
        return v;
    }

    else if (n == 0)
    {
        vector<string> v;
        v.push_back(X.substr(0, m));
        return v;
    }

    if (X[m - 1] == Y[n - 1])
    {
        vector<string> scs = printAllShortestCommonSupersequence(X, Y, m - 1, n - 1);

        for (string &str : scs)
            str.push_back(X[m - 1]);

        return scs;
    }

    if (lookup[m - 1][n] < lookup[m][n - 1])
    {
        vector<string> scs = printAllShortestCommonSupersequence(X, Y, m - 1, n);
        for (string &str : scs)
            str.push_back(X[m - 1]);
        return scs;
    }

    if (lookup[m][n - 1] < lookup[m - 1][n])
    {
        vector<string> scs = printAllShortestCommonSupersequence(X, Y, m, n - 1);

        for (string &str : scs) str.push_back(Y[n - 1]);

        return scs;
    }

    vector<string> top = printAllShortestCommonSupersequence(X, Y, m - 1, n);
    for (string &str : top)str.push_back(X[m - 1]);

    vector<string> left = printAllShortestCommonSupersequence(X, Y, m, n - 1);
    for (string &str : left)str.push_back(Y[n - 1]);

    top.insert(top.end(), left.begin(), left.end());
    return top;
}
void lengthOFShortestCommonSupersequence(string X, string Y,int m ,int n)
{
    for (int i = 0; i <= m ; ++i) lookup[i][0] = i;
    for (int j = 0; j <= n ; ++j) lookup[0][j] = j;


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
    vector<string> v = printAllShortestCommonSupersequence(X,Y,X.length(),Y.length());
    set<string> scs = set(v.begin(),v.end());
    for (auto i : scs) cout << i<<"\n";
    return 0;
}