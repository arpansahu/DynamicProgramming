#include <iostream>
#include<vector>
#include <limits.h>


using namespace std;


void longestAlternatingPositiveAndNegativeSubArray(int arr[],int n){
    int max_len = 1;
    int ending_index  = 0;
    int curr_len = 1;

    for (int i = 1; i < n; ++i) {
        if(arr[i] * arr[i-1] < 0){
            curr_len++;

            if(curr_len > max_len){
                max_len = curr_len;
                ending_index = i;
            }
        }
        else{
            curr_len = 1;
        }
    }
    cout<<"Longest allternating subarray : ";
    for (int j = ending_index - max_len + 1; j <= ending_index ; ++j) cout<<arr[j]<<" "; cout<<endl;
}



// main function
int main()
{
    int arr[] =  { 1, -2, 6, 4, -3, 2, -4, -3 };
    int n  = (*(&arr + 1) - arr);

    longestAlternatingPositiveAndNegativeSubArray(arr,n);

    return 0;
}
