#include<iostream>
#include <set>
#include <algorithm>

using namespace std;
int lookup[20][20];

string  LongestRepeatingSubsequence(string X,int m,int n){
    if(m == 0 || n == 0) return string("");
    if(X[m - 1] == X[n - 1] && m != n) return LongestRepeatingSubsequence(X,m-1,n-1) + X[m-1];
    if(lookup[m-1][n] > lookup[m][n-1]) return LongestRepeatingSubsequence(X,m-1,n);
    else return  LongestRepeatingSubsequence(X,m,n-1);
}

void lengthOFLongestRepeatingSubsequence(string X,int n){
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(X[i - 1] == X[j - 1] && i != j) lookup[i][j] = lookup[i - 1][j - 1] + 1;
            else lookup[i][j] = max(lookup[i][j - 1],lookup[i - 1][j]);
        }
    }
}

int main()
{
    string X = "ATACTCGGA";
    int m = X.length();
    lengthOFLongestRepeatingSubsequence(X,m);
    cout<<LongestRepeatingSubsequence(X,m,m);
    return 0;
}