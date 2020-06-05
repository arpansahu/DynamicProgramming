#include<iostream>
#include <vector>
#include <set>

using namespace std;
int lookup[20][20];

int LengthOFLongestBitonicSubsequence(vector<int> arr){
    vector<int> I(arr.size()) , D(arr.size());
    int n = arr.size() -1;

    I[0] = 1;
    for (int i = 1; i <= n ; ++i) {
        for (int j = 0; j < i ; ++j) {
            if(arr[j] < arr[i] && I[j] > I[i]) I[i] = I[j];
        }
        I[i]++;
    }

    D[n] = 1;
    for (int i = n - 1; i >= 0 ; i--) {
        for (int j = n; j > i ; j--) {
            if(arr[j] < arr[i] && D[j] > D[i]) D[i] = D[j];
        }
        D[i]++;
    }

    int lbs = 1;
    for (int i = 0; i <= n ; ++i) lbs = max(lbs,I[i] + D[i] - 1);
    return lbs;
}


int main()
{
    vector<int> arr { 4, 2, 5, 9, 7, 6, 10, 3, 1 };

    cout <<LengthOFLongestBitonicSubsequence(arr);
    return 0;
}