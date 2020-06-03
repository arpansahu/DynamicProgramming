#include<iostream>
#include <cstring>
#include <set>

using namespace std;

string LCSubstring(string X,string Y){
    int m = X.length(), n = Y.length();
    int lookup[m + 1][n + 1];
    int maxlen = 0;
    int endingIndex = m;
    memset(lookup,0, sizeof(lookup));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(X[i - 1] == Y[j - 1]) lookup[i][j] = lookup[i - 1][j - 1] + 1;
            if(lookup[i][j] > maxlen){
                maxlen = lookup[i][j];
                endingIndex = i;
            }
        }
    }
    return  X.substr(endingIndex - maxlen,maxlen);
}

int main()
{
    string X = "ABC", Y = "BABA";
    //unlike Longest common subsequence , substring needs to be consecutive
    cout<< LCSubstring(X, Y);
    return 0;
}