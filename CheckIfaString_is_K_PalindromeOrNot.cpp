#include <iostream>
using  namespace std;
#include <algorithm>
#include <unordered_map>

int isKPalindromeRecusrive(string X,int m , string Y, int n)
{
    if (m == 0 || n == 0)return n + m;
    if (X[m - 1] == Y[n - 1])return isKPalindromeRecusrive(X, m - 1, Y, n - 1);
    int x = isKPalindromeRecusrive(X, m - 1, Y, n);
    int y = isKPalindromeRecusrive(X, m, Y, n - 1);
    return 1 + min(x, y);
}
unordered_map <string,int> lookup;

int isKPalindromeMemoization(string X,int m,string Y,int n){
    if (m == 0 || n == 0)return n + m;
    if(X[m-1] == Y[n-1]) return isKPalindromeMemoization(X,m-1,Y,n-1);

    string key = to_string(m) + "|" + to_string(n);

    if(lookup.find(key) == lookup.end()){
        int x = isKPalindromeMemoization(X,m-1,Y,n);
        int y = isKPalindromeMemoization(X,m,Y,n-1);
        lookup[key] = 1 + min(x,y);
    }

    return lookup[key];
}

int isKPalindromeTabulisation(string X,string Y,int K){
    int m = X.length(), n = Y.length();

    int lookup[m+1][n+1];
    for (int i = 0; i <= m ; i++) {
        for (int j = 0; j <= n  ; j++) {
            if (i == 0 || j == 0) lookup[i][j] = i + j;
            else if (X[i-1] == Y[j-1]) lookup[i][j] = lookup[i-1][j-1];
            else lookup[i][j] = 1 + min(lookup[i-1][j],lookup[i][j-1]);
        }
    }
    return (lookup[m][n] <= 2 * K );
}

int isKPalindromeTabulisationUsingLongestCommonSubsequence(string X,string Y,int K){
    int m = X.length(), n = Y.length();

    int lookup[m+1][n+1];
    for (int i = 0; i <= m ; i++) {
        for (int j = 0; j <= n  ; j++) {
            if (i == 0 || j == 0) lookup[i][j] = 0;
            else if (X[i-1] == Y[j-1]) lookup[i][j] = lookup[i-1][j-1] + 1;
            else lookup[i][j] = max(lookup[i-1][j],lookup[i][j-1]);
        }
    }
    return (  n - lookup[m][n]  <= K );
}

int main()
{

    string str = "ABCDBA"; //"ABCDBA"  ABCDECA
    int K = 1;

    string rev = str;
    reverse(rev.begin(), rev.end());

    if (isKPalindromeRecusrive(str, str.length(), rev, str.length()) <= 2 * K)   cout << "String is K-Palindrome";
    else    cout << "String is not a K-Palindrome ";
    cout<<endl;
    if (isKPalindromeMemoization(str, str.length(), rev, str.length()) <= 2 * K)   cout << "String is K-Palindrome";
    else    cout << "String is not a K-Palindrome";
    cout<<endl;
    if (isKPalindromeTabulisation(str, rev, K))   cout << "String is K-Palindrome";
    else    cout << "String is not a K-Palindrome";
    cout<<endl;


    if (isKPalindromeTabulisationUsingLongestCommonSubsequence(str, rev, K))   cout << "String is K-Palindrome";
    else    cout << "String is not a K-Palindrome";
    cout<<endl;
    return 0;
}