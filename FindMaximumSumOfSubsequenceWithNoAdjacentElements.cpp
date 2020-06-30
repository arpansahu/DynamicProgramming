#include <iostream>
#include <unordered_map>
#include <climits>
#include <cstring>

using namespace std;

int maxSumSubseqRecursive(int *arr, int i, int n , int prev){
    if(i == n)  return 0;

    int exclude = maxSumSubseqRecursive(arr, i + 1, n, prev);
    int include =0;

    if(prev + 1 != i) include = maxSumSubseqRecursive(arr, i + 1, n, i) + arr[i];

    return max(include,exclude);
}

unordered_map<string,int> lookup;

int maxSumSubseqMemoization(int *arr, int i, int n , int prev){
    if(i == n)  return 0;

    string key = to_string(i) + "|" + to_string(n) + "|" + to_string(prev);

    if(lookup.find(key) == lookup.end())
    {
        int exclude = maxSumSubseqMemoization(arr, i + 1, n, prev);
        int include =0;
        if(prev + 1 != i) include = maxSumSubseqMemoization(arr, i + 1, n, i) + arr[i];

        lookup[key] =  max(include,exclude);
    }
    return lookup[key];
}

int maxSumSubseqTabulisation(int arr[],int n){
    if(n == 1) return arr[0];

    int lookup[n];
    lookup[0] = arr[0];
    lookup[1] = max(arr[0],arr[1]);

    for (int i = 2; i < n ; ++i) {
        lookup[i] = max(lookup[i-1],lookup[i-2] + arr[i]);
        lookup[i] =  max(lookup[i],arr[i]);
    }
    return lookup[n-1];
}

int maxSumSubseqTabulisationSpaceOptimised(int arr[],int n){
    if(n == 1) return arr[0];


    int first = arr[0];
    int second  = max(arr[0],arr[1]);

    for (int i = 2; i < n ; ++i) {
        int curr = max(second,first + arr[i]);
        curr =  max(curr,arr[i]);

        first = second;
        second = curr;
    }
    return second;
}


int main(void)
{
    int arr[] = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
    int n = (*(&arr + 1) - arr);

    cout << "Maximum sum is " << maxSumSubseqRecursive(arr, 0, n, INT_MIN)<<endl;
    cout << "Maximum sum is " << maxSumSubseqMemoization(arr, 0, n, INT_MIN)<<endl;
    cout << "Maximum sum is " << maxSumSubseqTabulisation(arr, n)<<endl;
    cout << "Maximum sum is " << maxSumSubseqTabulisationSpaceOptimised(arr, n)<<endl;

    return 0;
}