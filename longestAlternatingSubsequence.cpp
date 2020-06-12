#include<iostream>
#include <vector>
using namespace std;

int findLongestSequence(int arr[],int n){
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int counttemp = 1;

        bool cond =(arr[i] < arr[i+1]) ? false : true;

        int lastindex = i;
        for (int j = i + 1; j < n ; ++j) {
            if(cond){
                if(arr[j] < arr[lastindex]){
                    lastindex = j;
                    counttemp++;
                    cond = false;
                }
            }
            if(!cond){
                if(arr[j] > arr[lastindex]){
                    lastindex = j;
                    counttemp++;
                    cond = true;
                }
            }
        }
        if(counttemp > count) count = counttemp;
    }
    return count;
}

void printLongestSequence(int arr[],int n){
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        temp.push_back(arr[i]);

        bool cond =(arr[i] < arr[i+1]) ? false : true;

        int lastindex = i;
        for (int j = i + 1; j < n ; ++j) {
            if(cond){
                if(arr[j] < arr[lastindex]){
                    lastindex = j;
                    temp.push_back(arr[lastindex]);
                    cond = false;
                }
            }
            if(!cond){
                if(arr[j] > arr[lastindex]){
                    lastindex = j;
                    temp.push_back(arr[lastindex]);
                    cond = true;
                }
            }
        }

        if(temp.size() > v.size()) v = temp;
    }
    cout<<endl;
    for(auto i : v) cout<<i<<" ";
}

int main()
{
    int arr[] = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The length of Longest Subsequence is "<< findLongestSequence(arr, n);
    printLongestSequence(arr,n);
    return 0;
}