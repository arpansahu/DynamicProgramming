#include<iostream>
#include <cstring>
#include <unordered_map>
#include <set>


using namespace std;

int lengthOFLCPalindromeSubsequence(string X,int i,int j,unordered_map<string,int> &lookup){
    if(i > j) return 0;
    if( i == j) return 1;

    string key = to_string(i) + "|" + to_string(j);
    if(lookup.find(key) == lookup.end()){
        if(X[i] == X[j]) lookup[key] = lengthOFLCSubstring(X,i + 1,j - 1,lookup) + 2;
        else lookup[key] = max(lengthOFLCSubstring(X,i+1,j,lookup),lengthOFLCSubstring(X,i,j-1,lookup));
    }
    return lookup[key];
}

int main()
{
    string X = "ABBDCACB";
    unordered_map<string,int> lookup;
    cout<< lengthOFLCPalindromeSubsequence(X,0,X.length() - 1,lookup);
    return 0;
}