#include<iostream>
#include <unordered_map>
using namespace std;


int LCSTabulizationSpaceOptimizedUsingTwoArray(string X, string Y){  //using two array
    int m = X.length() ,n = Y.length();

    int curr[n+1] , prev[m+1];

    for (int i = 0; i <= m ; ++i) {
        for (int j = 0; j <= n ; ++j) {
            if(i == 0 || j ==0) curr[j] = 0;
            else{
                if(X[i-1] == Y[j-1]) curr[j] = prev[j - 1] + 1;
                else curr[j] = max(curr[j-1],prev[j]);
            }
        }

        for (int k = 0; k <= n; ++k) {prev[k] = curr[k];}
    }

    return curr[n];
}

int LCSTabulizationSpaceOptimizedUsingOneArray(string X, string Y){  //using two array
    int m = X.length() ,n = Y.length();

    int curr[n+1] , prev;

    for (int i = 0; i <= m ; ++i) {
        prev = curr[0];
        for (int j = 0; j <= n ; ++j) {
            int backup = curr[j];

            if(i == 0 || j ==0) curr[j] = 0;
            else{
                if(X[i-1] == Y[j-1]) curr[j] = prev + 1;
                else curr[j] = max(curr[j-1],curr[j]);
            }
            prev = backup;
        }

    }

    return curr[n];
}


int main(){
    string X = "XMJYAUZ", Y = "MZJAWXU";

    if (X.length() > Y.length())
        cout << "The length of LCS is " << LCSTabulizationSpaceOptimizedUsingTwoArray(X, Y);
    else
        cout << "The length of LCS is " << LCSTabulizationSpaceOptimizedUsingTwoArray(Y, X);
    cout<<"\n";
    if (X.length() > Y.length())
        cout << "The length of LCS is " << LCSTabulizationSpaceOptimizedUsingOneArray(X, Y);
    else
        cout << "The length of LCS is " << LCSTabulizationSpaceOptimizedUsingOneArray(Y, X);

    return 0;
}