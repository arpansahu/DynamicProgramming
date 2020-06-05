#include<iostream>
#include <climits>
#include <vector>
#include <numeric>
using namespace std;


void IncreasingSubsequenceWithMaximumSumprint(int arr[],int size){
    int sum[size];
    vector<vector<int>> vec(size);

    for (int k = 0; k < size; ++k) sum[k] = 0;
    sum[0] = arr[0];
    vec[0].push_back(arr[0]);
    for (int i = 1; i < size ; ++i) {
        for (int j = 0; j < i ; ++j) {
            if(arr[j] < arr[i] && sum[j] > sum[i]) {
                sum[i] = sum[j];
                vec[i] = vec[j];
            }
        }
        sum[i] += arr[i];
        vec[i].push_back(arr[i]);
    }
    int maximum = INT_MIN;
    int index = 0;
    int count = 0;
    for(auto i : sum) {
        if(i > maximum) {
            maximum = i;
            index = count;
        }
        count++;
    }
    for(auto i : vec[index]) cout <<i<<" ";
}

int main()
{
    int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 };
    int size = (*(&arr + 1) - arr);

    IncreasingSubsequenceWithMaximumSumprint(arr,size);
    return 0;
}