#include <iostream>
#include <unordered_map>
#include <climits>
#include <cstring>
using namespace std;

int findMinJumpsRecursive(int arr[],int i,int n){
    if(i == n-1) return 0;

    if(i >= n || arr[i] == 0) return INT_MAX;

    int min_jumps = INT_MAX;
    for (int j = i + 1; j <= i + arr[i] ; ++j) {
        int cost  = findMinJumpsRecursive(arr,j,n);
        if(cost != INT_MAX) min_jumps = min(min_jumps,cost + 1);
    }
    return min_jumps;
}
unordered_map<string,int> lookup;

int findMinJumpsMemoization(int arr[],int i,int n){
    if(i == n-1) return 0;

    if(i >= n || arr[i] == 0) return INT_MAX;

    string key = to_string(i) + "|" + to_string(n);

    if(lookup.find(key) == lookup.end()){
        lookup[key]  = INT_MAX;
        for (int j = i + 1; j <= i + arr[i] ; ++j) {
            int cost  = findMinJumpsRecursive(arr,j,n);
            if(cost != INT_MAX) lookup[key]  = min(lookup[key],cost + 1);
        }
    }
    return lookup[key];
}

int findMinJumpsTabulisation(int arr[],int n){
    if(arr[0] == 0) return INT_MAX;

    int lookup[n];
    for (int i = 0; i < n ; ++i) lookup[i] = INT_MAX;

    lookup[0] = 0;

    for (int i = 0; i < n; ++i) {
        cout<<i<<"\n";
        for (int j = 1; (i + j < n) &&  j <= min(n-1,arr[i]) ; ++j) {
            lookup[i+j] = (lookup[i+j] != INT_MAX) ? min(lookup[i+j],lookup[i]+1) : lookup[i] + 1;
            for(auto  i : lookup ) cout<<i<<" ";cout<<endl;
        }
    }

    return lookup[n-1];
}

int main(void)
{
    int arr[] = { 1, 3, 6, 1, 0, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum jumps required to reach the destination are %d\n",findMinJumpsRecursive(arr, 0, n));
    printf("Minimum jumps required to reach the destination are %d\n",findMinJumpsMemoization(arr, 0, n));
    printf("Minimum jumps required to reach the destination are %d\n",findMinJumpsTabulisation(arr,  n));
    return 0;
}