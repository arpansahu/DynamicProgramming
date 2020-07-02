#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

bool interleavedRecusrive(string X,string Y,string S){
    if(!X.length() && !Y.length() && !S.length()) return  1;
    if(!S.length()) return 0;

    bool x = (X.length() && S[0] == X[0]) && interleavedRecusrive(X.substr(1),Y,S.substr(1));
    bool y = (Y.length() && S[0] == Y[0]) && interleavedRecusrive(X,Y.substr(1),S.substr(1));
    return x || y;
}

unordered_map<string,bool> lookup;

bool interleavedMemoization(string X,string Y,string S){
    if(!X.length() && !Y.length() && !S.length()) return  1;
    if(!S.length()) return 0;

    string key = to_string(X.length()) + "|" + to_string(Y.length()) + "|" + to_string(S.length());

    if(lookup.find(key) == lookup.end()){
        bool x = (X.length() && S[0] == X[0]) && interleavedRecusrive(X.substr(1),Y,S.substr(1));
        bool y = (Y.length() && S[0] == Y[0]) && interleavedRecusrive(X,Y.substr(1),S.substr(1));
        lookup[key] =  x || y;
    }
    return lookup[key];
}

bool interleavedTabulisation(string X,string Y,string S){
    int M = X.size();
    int N = Y.size();

    if(M+N != S.size()) return  false;

    bool lookup[M+1][N+1];

    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0 && j == 0)  lookup[i][j] = true;

            else if (i and j and X[i - 1] == S[i + j - 1] and Y[j - 1] == S[i + j - 1])lookup[i][j] = lookup[i - 1][j] || lookup[i][j - 1];
            
            else if (i and X[i - 1] == S[i + j - 1])lookup[i][j] = lookup[i - 1][j];
            
            else if (j and Y[j - 1] == S[i + j - 1])lookup[i][j] = lookup[i][j - 1];
        }
    }
    return lookup[M][N];
}


int main()
{
    string X = "ABC";
    string Y = "DEF";
    string S = "ADEBCF";

    if (interleavedRecusrive(X, Y, S))cout << "Given string is interleaving of X and Y\n";
    else cout << "Given string is not an interleaving of X and Y\n";

    if (interleavedMemoization(X, Y, S))cout << "Given string is interleaving of X and Y\n";
    else cout << "Given string is not an interleaving of X and Y\n";

    if (interleavedTabulisation(X, Y, S))cout << "Given string is interleaving of X and Y\n";
    else cout << "Given string is not an interleaving of X and Y\n";

    return 0;
}
