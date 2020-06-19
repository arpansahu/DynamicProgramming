#include <iostream>
using  namespace std;
#include <algorithm>
#include <unordered_map>
#include <cstring>

int isMatchingRecursive(string str,string pattern,int m ,int n){
    if(m < 0 && n < 0) return 1;
    else if (n < 0) return 0;
    else if(m < 0)
    {
        for (int i = 0; i <= n ; ++i)   if ( pattern[i] != '*') return 0;
        return 1;
    }
    if(pattern[n] == '*') return isMatchingRecursive(str,pattern,n-1,m) + isMatchingRecursive(str,pattern,n,m-1);
    else {
        if(pattern[n] != '?' && pattern[n] != str[m]) return 0;
        else return isMatchingRecursive(str,pattern,n-1,m-1);
    }
}
unordered_map <string,int> lookup;

int isMatchingMemoization(string str,string pattern,int m ,int n){
    if(m < 0 && n < 0) return 1;
    else if (n < 0) return 0;
    else if(m < 0)
    {
        for (int i = 0; i <= n ; ++i)   if ( pattern[i] != '*') return 0;
        return 1;
    }
    string key = to_string(m) + "|" + to_string(n);


    if(pattern[n] == '*') return isMatchingRecursive(str,pattern,n-1,m) + isMatchingRecursive(str,pattern,n,m-1);
    else {
        if(pattern[n] != '?' && pattern[n] != str[m]) return 0;
        else return isMatchingRecursive(str,pattern,n-1,m-1);
    }
}

int isMatchingTabulisation(string str, string pattern, int m, int n){

    bool lookup[m + 1][n + 1];


    lookup[0][0] = true;


    for (int j = 1; j <= n; j++)    if (pattern[j - 1] == '*') lookup[0][j] = lookup[0][j - 1];


    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pattern[j-1] == '*')
                lookup[i][j] = lookup[i - 1][j] || lookup[i][j - 1];

            else if (pattern[j-1] == '?' || str[i-1] == pattern[j-1])
                lookup[i][j] = lookup[i - 1][j - 1];
        }
    }

    return lookup[m][n];
}

int main(void) {
    string str = "xyxzzxy";
    string pattern = "x***x?";


    if (isMatchingRecursive(str, pattern, str.length() - 1, pattern.length() - 1))
        printf("Match");
    else
        printf("No Match");

    cout<<endl;

    if (isMatchingMemoization(str, pattern, str.length() - 1, pattern.length() - 1))
        printf("Match");
    else
        printf("No Match");

    cout<<endl;

    if (isMatchingTabulisation(str, pattern, str.length() - 1, pattern.length() - 1))
        printf("Match");
    else
        printf("No Match");

    return 0;
}