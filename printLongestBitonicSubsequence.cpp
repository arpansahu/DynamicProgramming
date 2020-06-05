#include<iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int lookup[20][20];

void LongestBitonicSubsequence(int arr[],int n){
    vector<vector<int>> I(n + 1) , D(n + 1);
    I[0].push_back(arr[0]);

    for (int i = 1; i <= n ; ++i) {
        for (int j = 0; j < i ; ++j) {
            if(arr[j] < arr[i] && I[j].size() > I[i].size()) I[i] = I[j];
        }
        I[i].push_back(arr[i]);
    }

    D[n].push_back(arr[n]);
    for (int i = n - 1; i >= 0 ; i--) {
        for (int j = n ; j > i ; j--) {
            if(arr[j] < arr[i] && D[j].size() > D[i].size()) D[i] = D[j];
        }
        D[i].push_back(arr[i]);
    }
    vector<int> final(0);
    for (int i = 0; i <= n ; ++i) {
        if(I[i].size() + D[i].size() > final.size()){
            D[i].pop_back();
            reverse(D[i].begin(),D[i].end());
            I[i].insert(I[i].end(),D[i].begin() ,D[i].end());
            final = I[i];
        }
    }

    for(auto i : final) cout <<i<<" ";

}


int main()
{
    int arr[] =  { 4, 2, 5, 9, 7, 6, 10, 3, 1 };
    int size = (*(&arr + 1) - arr);
    LongestBitonicSubsequence(arr,size - 1);
    return 0;
}