#include<iostream>
#include <climits>
#include <vector>
using namespace std;


void LongestIncreasingSubsequence(int arr[],int size){
    vector<vector<int>> L(size);
    L[0].push_back(arr[0]);

    for (int i = 1; i < size ; ++i) {
        for (int j = 0; j < i ; ++j) {
            if(arr[j] < arr[i] && L[j].size() > L[i].size()) L[i] = L[j];
        }
        L[i].push_back(arr[i]);
    }
    vector<int> final(0);
    for(auto i : L) if(final.size() < i.size()) final = i;
    for(auto i : final) cout << i <<" ";
    cout << endl;
}

int main()
{
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int size = (*(&arr + 1) - arr);

    LongestIncreasingSubsequence(arr,size);
    return 0;
}