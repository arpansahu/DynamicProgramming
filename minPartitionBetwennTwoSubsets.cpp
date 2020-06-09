#include<iostream>
#include <unordered_map>

using namespace std;

int minPartitionRecursion(int S[],int n,int s1,int s2){
    if(n < 0) return abs(s1-s2);
    int include = minPartitionRecursion(S,n-1,s1+S[n],s2);
    int exclude = minPartitionRecursion(S,n-1,s1,s2+S[n]);
    return min(include,exclude);
}

unordered_map <string,int> lookup;

int minPartitionMemoization(int S[],int n,int s1,int s2){
    if(n < 0) return abs(s1-s2);
    string key = to_string(n) + "|" + to_string(s1) + "|" + to_string(s2);

    if(lookup.find(key) == lookup.end()){
        int include = minPartitionMemoization(S,n-1,s1+S[n],s2);
        int exclude = minPartitionMemoization(S,n-1,s1,s2+S[n]);
        lookup[key] = min(exclude,include);
    }
    return lookup[key];
}



int main()
{
    int S[] = { 10, 20, 15, 5, 25};
    int n = (*(&S + 1) - S);

    cout << "The minimum difference is " << minPartitionRecursion(S, n - 1, 0, 0)<<"\n";
    cout << "The minimum difference is " << minPartitionMemoization(S, n - 1, 0, 0)<<"\n";

    return 0;
}