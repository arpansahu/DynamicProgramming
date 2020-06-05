#include<iostream>
#include <climits>
using namespace std;


int LongestIncreasingSubsequenceLengthUsingRecusion(int arr[],int i ,int n , int prev){
    if(i == n) return 0;
    int excl = LongestIncreasingSubsequenceLengthUsingRecusion(arr,i  + 1, n ,prev);
    int incl = 0;
    if(arr[i] > prev) incl = 1 + LongestIncreasingSubsequenceLengthUsingRecusion(arr,i+1,n,arr[i]);
    return max(incl,excl);
}

void LongestIncreasingSubsequenceLengthUsingtabulisation(int arr[],int size){
    int L[size];
    for (int i = 0; i < size; ++i) L[i] = 0;

    L[0] = 1;
    for (int i = 1; i < size ; ++i) {
        for (int j = 0; j < i ; ++j) {
            if(arr[j] < arr[i] && L[j] > L[i]) L[i] = L[j];
        }
        L[i]++;
    }
    int lis =  INT_MIN;
    for(auto i : L) if(lis < i) lis = i;
    cout  << lis << endl;
}

int main()
{
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int size = (*(&arr + 1) - arr);
    cout << LongestIncreasingSubsequenceLengthUsingRecusion(arr,0,size,INT_MIN)<<endl;
    LongestIncreasingSubsequenceLengthUsingtabulisation(arr,size);
    return 0;
}