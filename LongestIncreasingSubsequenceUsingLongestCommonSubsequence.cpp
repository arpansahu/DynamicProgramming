#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

int removeDuplicates(int Y[],int n){
    int k = 0;
    for (int i = 1; i < n; ++i) if(Y[i] != Y[k]) Y[++k] = Y[i];
    return k +1;
}

int LCSLengthRecursive(int X[],int Y[],int n,int m){
    if(m == 0 || n ==0) return 0;
    if(X[n] == Y[m]) return LCSLengthRecursive(X,Y,n-1,m-1) + 1;
    else return max(LCSLengthRecursive(X,Y,n-1,m),LCSLengthRecursive(X,Y,n,m-1));
}

int findLISUsingLCSRecursive(int arr[],int n){
    int Y[n];

    for (int i = 0; i < n; ++i) Y[i] = arr[i];
    sort(Y,Y+n);

    int m  = removeDuplicates(Y,n);

    return LCSLengthRecursive(arr,Y,n,m);

}
unordered_map<string,int> lookup;

int LCSLengthMemoization(int X[],int Y[],int n,int m){
    if(m == 0 || n ==0) return 0;
    string key  = to_string(n) + "|" +  to_string(m);

    if(lookup.find(key) == lookup.end()){
        if(X[n] == Y[m]) lookup[key] =  LCSLengthMemoization(X,Y,n-1,m-1) + 1;
        else lookup[key] =  max(LCSLengthMemoization(X,Y,n-1,m),LCSLengthMemoization(X,Y,n,m-1));
    }
    return lookup[key];
}

int findLISUsingLCSMemoization(int arr[],int n){
    int Y[n];

    for (int i = 0; i < n; ++i) Y[i] = arr[i];
    sort(Y,Y+n);

    int m  = removeDuplicates(Y,n);

    return LCSLengthMemoization(arr,Y,n,m);

}


int LCSLengthTabulisation(int X[],int Y[],int n,int m){
    int lookup[n+1][m+1];
    memset(lookup,0,sizeof lookup);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (X[i - 1] == Y[j - 1]) lookup[i][j] = lookup[i - 1][j - 1] + 1;
            else lookup[i][j] = max(lookup[i][j - 1], lookup[i - 1][j]);
        }
    }
    return lookup[n][m];
}

int findLISUsingLCSTabulisation(int arr[],int n){
    int Y[n];

    for (int i = 0; i < n; ++i) Y[i] = arr[i];
    sort(Y,Y+n);

    int m  = removeDuplicates(Y,n);

    return LCSLengthTabulisation(arr,Y,n,m);

}
int main()
{
    int X[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(X)/sizeof(X[0]);

    cout << "The length of LIS is " << findLISUsingLCSRecursive(X, n)<<endl;
    cout << "The length of LIS is " << findLISUsingLCSMemoization(X, n)<<endl;
    cout << "The length of LIS is " << findLISUsingLCSTabulisation(X, n)<<endl;


    return 0;
}