#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int kadaneForPositiveNegative (int arr[],int n){
    int max_so_far = 0;
    int max_ending_here = 0;

    for (int i = 0; i < n; ++i) {
        max_ending_here = max_ending_here + arr[i];
        max_ending_here = max(max_ending_here,0);
        max_so_far = max(max_so_far,max_ending_here);
    }
    return max_so_far;
}

void printkadaneForPositiveNegative (int arr[],int n){
    int max_so_far = 0;
    int max_ending_here = 0;
    int lastIndex = 0;
    int startIndex = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        max_ending_here = max_ending_here + arr[i];

        if(max_ending_here < 0 ){
            max_ending_here = 0;
            s = i + 1;
        }

        int check  = max_so_far;
        max_so_far = max(max_so_far,max_ending_here);
        if(check != max_so_far) {
            startIndex = s;
            lastIndex = i ;
        }
    }
    cout<<"Using Kadane Mix :- Max sum is : "<< max_so_far << "   ";
    for (int j =  startIndex; j <= lastIndex ; ++j) cout<<arr[j]<<" ";cout<<endl;
}

int kadaneForAllNegative (int arr[],int n){
    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    for (int i = 1; i < n; ++i) {
        max_ending_here = max_ending_here + arr[i];
        max_ending_here = max(max_ending_here,arr[i]);
        max_so_far = max(max_so_far,max_ending_here);
    }
    return max_so_far;
}

void printkadaneForAllNegative (int arr[],int n){
    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    int lastIndex = 0;
    int startIndex = 0;
    int s = 0;

    for (int i = 1; i < n; ++i) {
        max_ending_here = max_ending_here + arr[i];

        if(max_ending_here < arr[i]){
            s = i ;
            max_ending_here = arr[i];
        }
        int check = max_so_far;
        max_so_far = max(max_so_far,max_ending_here);
        if(check != max_so_far) {
            startIndex = s;
            lastIndex = i ;
        }
    }

    cout<<"Using Kadane NEgative :-  Max sum is : "<< max_so_far << "   ";
    for (int j =  startIndex; j <= lastIndex ; ++j) cout<<arr[j]<<" ";cout<<endl;
}


int kadaneUniversal(int arr[],int n){
    int max_so_far = INT_MIN;
    int max_ending_here = arr[0];

    for (int i = 0; i < n; ++i) {
        max_ending_here = max_ending_here + arr[i];
        max_so_far = max(max_so_far,max_ending_here);
        max_ending_here = max(max_ending_here,0);
    }
    return max_so_far;
}

void printkadaneUniversal (int arr[],int n){
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    int lastIndex = 0;
    int startIndex = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        max_ending_here = max_ending_here + arr[i];

        int check  = max_so_far;
        max_so_far = max(max_so_far,max_ending_here);
        if(check != max_so_far) {
            startIndex = s;
            lastIndex = i ;
        }

        if(max_ending_here < 0 ){
            max_ending_here = 0;
            s = i + 1;
        }

    }
    cout<<"Using Kadane Universal :- Max sum is : "<< max_so_far << "   ";
    for (int j =  startIndex; j <= lastIndex ; ++j) cout<<arr[j]<<" ";cout<<endl;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int arr1[] = { -8, -3, -6, -2, -5, -4 };

    cout << "Using Kadane Mix The sum of contiguous sub-array with the largest sum is " <<kadaneForPositiveNegative(arr, (*(&arr+1)-arr))<<endl;
    printkadaneForPositiveNegative(arr,(*(&arr+1)-arr));
    cout << "Using kadane Negative The sum of contiguous sub-array with the largest sum is " <<kadaneForAllNegative(arr1, (*(&arr1+1)-arr1))<<endl;
    printkadaneForAllNegative(arr1,(*(&arr1+1)-arr1));

    cout << "Using Kadane Universal The sum of contiguous sub-array with the largest sum is " <<kadaneUniversal(arr, (*(&arr+1)-arr))<<endl;
    printkadaneUniversal(arr,(*(&arr+1)-arr));
    cout << "Using Kadane Universal The sum of contiguous sub-array with the largest sum is " <<kadaneUniversal(arr1, (*(&arr1+1)-arr1))<<endl;
    printkadaneUniversal(arr1,(*(&arr1+1)-arr1));

    return 0;
}