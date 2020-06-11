#include<iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int countRecurisveNonUniqueSubsets(int S[],int n,int totalMoney){
    if(totalMoney == 0) return  1;
    if(totalMoney < 0) return 0;
    int count = 0;
    for (int i = 0; i < n; ++i)count += countRecurisveNonUniqueSubsets(S,n,totalMoney - S[i]);
    return count;
}

int countRecursiveUniqueSubsets(int S[],int n,int totalMoney){
    if(totalMoney == 0) return 1;
    if(totalMoney <  0 || n  < 0 ) return 0;
    int include = countRecursiveUniqueSubsets(S,n,totalMoney - S[n]);
    int exclude = countRecursiveUniqueSubsets(S,n-1,totalMoney);
    return include + exclude;
}

unordered_map<string,int> lookup;

int countTabulisationUniqueSubsets(int S[],int n,int totalMoney){
    if(totalMoney == 0) return 1;
    if(totalMoney <  0 || n  < 0 ) return 0;
    string key = to_string(n)  + "|" + to_string(totalMoney);

    if(lookup.find(key) == lookup.end()){
        int include = countRecursiveUniqueSubsets(S,n,totalMoney - S[n]);
        int exclude = countRecursiveUniqueSubsets(S,n-1,totalMoney);
        lookup[key] =  include + exclude;
    }
    return lookup[key];
}

int main()
{
    int S[] = { 1, 2, 3 };
    int n = sizeof(S) / sizeof(S[0]);
    int N = 4;


    cout << "Total number of ways to get desired change is "<< countRecurisveNonUniqueSubsets(S, n, N)<<endl;
    cout << "Total number of ways to get desired change is "<< countRecursiveUniqueSubsets(S, n - 1, N)<<endl;
    cout << "Total number of ways to get desired change is "<< countTabulisationUniqueSubsets(S, n - 1, N)<<endl;

    return 0;
}