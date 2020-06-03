#include<iostream>


using namespace std;
int lookup[20][20];

void diff(string X,string Y,int m,int n){
    if (m > 0 && n > 0 && X[m - 1] == Y[n - 1])
    {
        diff(X, Y, m - 1, n - 1);
        cout << "  " << X[m - 1];
    }
    
    else if (n > 0 && (m == 0 || lookup[m][n - 1] >= lookup[m - 1][n]))
    {
        diff(X, Y, m, n - 1);
        cout << " +" << Y[n - 1];
    }

    else if (m > 0 && (n == 0 || lookup[m][n - 1] < lookup[m - 1][n]))
    {
        diff(X, Y, m - 1, n);
        cout << " -" << X[m - 1];
    }

}

void lengthOFLongestCommonSubsequence(string X,string Y,int m,int n){
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(X[i - 1] == Y[j - 1]) lookup[i][j] = lookup[i - 1][j - 1] + 1;
            else lookup[i][j] = max(lookup[i][j - 1],lookup[i - 1][j]);
        }
    }
}

int main()
{
    string X = "ABCDFGHJQZ";
    string Y = "ABCDEFGIJKRXYZ";
    int m = X.length(), n = Y.length();
    lengthOFLongestCommonSubsequence(X,Y,m,n);
    diff(X,Y,m,m);
    return 0;
}