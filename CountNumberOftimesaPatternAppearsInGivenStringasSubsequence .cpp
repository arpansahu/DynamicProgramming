#include<iostream>
#include <vector>
using namespace std;

int countrecursive(string X,string Y,int m,int n){
    if(m == 0 && n == 0) return X[0] == Y[0];
    if(m == 0) return 0;
    if(n == 0) return 1;
    if(n >  m) return 0;
    return ((X[m-1] == Y[n-1]) ? countrecursive(X,Y,m-1,n-1) : 0) + countrecursive(X,Y,m-1,n);
}

int countTabulisation(string X,string Y,int m,int n){

    int lookup[m + 1][n + 1];
    for (int i = 0; i <= m; i++) lookup[i][0] = 1;
    for (int j = 1; j <= n; j++) lookup[0][j] = 0;


    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)lookup[i][j] = ((X[i - 1] == Y[j - 1]) ? lookup[i - 1][j - 1] : 0) + lookup[i - 1][j];

    return lookup[m][n];
}
int main()
{
    string X = "subsequence";   // input string
    string Y = "sue";        // pattern
    cout<<countrecursive(X,Y,X.size(),Y.size()) <<endl;
    cout << countTabulisation(X, Y, X.size(), Y.size());

    return 0;
}