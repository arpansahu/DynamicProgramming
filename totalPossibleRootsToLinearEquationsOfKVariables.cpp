#include<iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int countNoOFRootsRecursive(int S[],int n,int totalRHS){
    if(totalRHS == 0) return 1;
    if(totalRHS < 0 || n < 0 ) return 0;
    int include = countNoOFRootsRecursive(S,n,totalRHS - S[n]);
    int exclude = countNoOFRootsRecursive(S,n-1,totalRHS);
    return include+exclude;
}
unordered_map<string,int> lookup;

int countNoOFRootsMemoization(int S[],int n,int totalRHS){
    if(totalRHS == 0) return 1;
    if(totalRHS < 0 || n < 0 ) return 0;
    string key = to_string(n) + "|" + to_string(totalRHS);
    if(lookup.find(key) == lookup.end()){
        int include = countNoOFRootsMemoization(S,n,totalRHS - S[n]);
        int exclude = countNoOFRootsMemoization(S,n-1,totalRHS);
        lookup[key] =  include+exclude;
    }
    return lookup[key];
}
int main()
{
    int S[] = { 1, 2, 3 };
    int n = sizeof(S) / sizeof(S[0]);
    int N = 4;

    cout << "Total number of ways to get desired change is "<< countNoOFRootsRecursive(S, n - 1, N)<<endl;
    cout << "Total number of ways to get desired change is "<< countNoOFRootsMemoization(S, n - 1, N)<<endl;

    return 0;
}