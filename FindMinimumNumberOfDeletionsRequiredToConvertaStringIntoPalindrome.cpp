#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;


int minDeletionsRecursive(string X,int i,int j){
    if(i >= j) return 0;
    if(X[i] == X[j])  return minDeletionsRecursive(X,i+1,j-1);
    return 1 + min(minDeletionsRecursive(X,i+1,j) , minDeletionsRecursive(X,i,j-1));
}

unordered_map<string,int> lookup;

int minDeletionsMemoization(string X,int i,int j){
    if(i >= j) return 0;
    string key = to_string(i) + "|" + to_string(j);
    if(lookup.find(key) == lookup.end()){
        if(X[i] == X[j])  lookup[key] =  minDeletionsRecursive(X,i+1,j-1);
        lookup[key] =  1 + min(minDeletionsRecursive(X,i+1,j) , minDeletionsRecursive(X,i,j-1));
    }
    return lookup[key];
}

int minDeletionsTabulisation(string X){
    int n = X.length();
    string Y = X;
    reverse(Y.begin(),Y.end());

    int lookup[n + 1][n + 1];
    memset(lookup,0,sizeof lookup);

    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(X[i-1] == Y[j-1]) lookup[i][j] = 1 + lookup[i-1][j-1];
            else lookup[i][j] = max(lookup[i][j-1],lookup[i-1][j]);
        }
    }
    return n - lookup[n][n];
}

int main()
{
    string X = "ACBCDBAA";
    int n = X.length();

    cout << "The minimum number of deletions required are " <<minDeletionsRecursive(X, 0, n - 1)<<endl;
    cout << "The minimum number of deletions required are " <<minDeletionsMemoization(X, 0, n - 1)<<endl;
    cout << "The minimum number of deletions required are " <<minDeletionsTabulisation(X)<<endl;

    return 0;
}