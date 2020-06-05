#include<iostream>
#include <string.h>

using namespace std;

int minimumcostOfMAkingTwoStringsEqual(string X,string Y,int m ,int n){
    //case 1
    if(m == 0) return n;
    if(n == 0) return m;
    int cost;

    //cose 2
    if(X[m - 1] == Y[n - 1]) cost = 0;
    else cost = 1;

    //case 3
    //                         deletion  case 3a                                    insetion case 3b                                                 substitution case 2 and 3c
    return min(min(minimumcostOfMAkingTwoStringsEqual(X,Y,m-1,n) + 1,minimumcostOfMAkingTwoStringsEqual(X,Y,m,n-1) + 1),minimumcostOfMAkingTwoStringsEqual(X,Y,m-1,n-1) + cost);
}

int minimumcostOfMAkingTwoStringsEqualTabulisation(string X,string Y,int m,int n ){
    int lookup[m + 1][n + 1];
    memset(lookup,0, sizeof(lookup));
    for (int i = 0; i <= m ; ++i) lookup[i][0] = i; //case 1
    for (int i = 0; i <= n ; ++i) lookup[0][i] = i; //case 2
    int substitutionCost ;
    for (int i = 1; i <= m ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(X[i - 1] == Y[j -1]) substitutionCost = 0;
            else substitutionCost = 1;
            lookup[i][j] = min(min(lookup[i -1][j] + 1,lookup[i][j - 1] + 1),lookup[i - 1][j - 1] + substitutionCost );
        }
    }
    return lookup[m][n];

}

int main()
{
    string X = "kitten", Y = "sitting";
    cout <<minimumcostOfMAkingTwoStringsEqual(X,Y,X.length(),Y.length())<<"\n";
    cout<<minimumcostOfMAkingTwoStringsEqualTabulisation(X,Y,X.length(),Y.length());
    return 0;
}