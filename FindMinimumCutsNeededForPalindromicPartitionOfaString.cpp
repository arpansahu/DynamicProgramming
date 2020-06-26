#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

bool isPalindrome(string X,int i,int j){
    while(i <= j) if(X[i++] != X[j--]) return false;
    return true;
}

int minPalinPartitionRecurisve(string X,int i, int j){
    //cout<<i<<"-"<<j<<"\n";
    if(i == j || isPalindrome(X,i,j)) return 0;
    int min  = INT_MAX;

    for (int k = i; k <= j -1 ; ++k) {
        int count  = 1 + minPalinPartitionRecurisve(X,i,k) + minPalinPartitionRecurisve(X,k+1,j);
        if(count < min) min = count;
    }
    return  min;
}

int isPalindromeCheck[20][20];
unordered_map<string,int> lookup;

void findAllPalindromes(string X,int n){
    for (int i = n-1; i >=0 ; i--) {
        for (int j = i; j < n ; ++j) {
            if(i == j) isPalindromeCheck[i][j] = 1;
            else if(X[i] == X[j]) isPalindromeCheck[i][j] = ((j - i == 1) ? true : isPalindromeCheck[i + 1][j - 1]);
            else isPalindromeCheck[i][j] = 0;
        }
    }
}

int minPalinPartitionMemoizationUtil(int i,int j){
    if(i == j || isPalindromeCheck[i][j]) return 0;

    string key = to_string(i) + "|" + to_string(j);

    if(lookup.find(key) == lookup.end()){
        lookup[key] = INT_MAX;
        for (int k = i; k <= j -1 ; ++k) {
            int count = 1 + minPalinPartitionMemoizationUtil(i,k) + minPalinPartitionMemoizationUtil(k+1,j);
            if( lookup[key] > count) lookup[key] = count;
        }
    }
    return lookup[key];
}

int minPalinPartitionMemoization(string X,int i,int j){
    findAllPalindromes(X,j+1);
    return minPalinPartitionMemoizationUtil(i,j);
}

int minPalinPartitionTabulisation(string X){
    int n = X.size();
    findAllPalindromes(X,n);
    int lookup[n];

    for (int i = n-1; i >= 0 ; i--) {
        lookup[i] = INT_MAX;
        if(isPalindromeCheck[i][n-1]) lookup[i] = 0;
        else {
            for (int j = n-2; j >= i ; j--) {
                if(isPalindromeCheck[i][j]) lookup[i] = min(lookup[i],1+lookup[j+1]);
            }
        }
    }
    return  lookup[0];
}

int main()
{
    string X = "BABABCBADCD";        // BAB|ABCBA|DCD
    int n = X.length();

    cout << "The minimum cuts required are "<< minPalinPartitionRecurisve(X, 0, n - 1)<<endl;
    cout << "The minimum cuts required are "<< minPalinPartitionMemoization(X, 0, n - 1)<<endl;
    cout << "The minimum cuts required are "<< minPalinPartitionTabulisation(X)<<endl;

    return 0;
}