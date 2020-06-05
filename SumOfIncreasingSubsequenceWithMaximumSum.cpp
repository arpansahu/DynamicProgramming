#include<iostream>
#include <climits>
#include <vector>
#include <numeric>
using namespace std;


void SumOfIncreasingSubsequenceWithMaximumSum(int arr[],int size){
    int sum[size];
    for (int k = 0; k < size; ++k) sum[k] = 0;
    sum[0] = arr[0];

    for (int i = 1; i < size ; ++i) {
        for (int j = 0; j < i ; ++j) {
            if(arr[j] < arr[i] && sum[j] > sum[i]) sum[i] = sum[j];
        }
        sum[i] += arr[i];
    }
    int maximum = INT_MIN;
    for(auto i : sum) if(i > maximum) maximum = i;
    cout <<maximum<<endl;
}

int main()
{
    int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 };
    int size = (*(&arr + 1) - arr);

    SumOfIncreasingSubsequenceWithMaximumSum(arr,size);
    return 0;
}