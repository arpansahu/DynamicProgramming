#include <iostream>
#include<vector>
#include <limits.h>


using namespace std;

template<size_t  n>
void LargestProductContiguousSubarray(int (&arr)[n])
{
    int product = 0;
    int max_ending  = 1;
    int min_ending = 1;


    int last_index = 0;
    int len = 0;


    for (int i = 0; i < n; ++i) {

        if(arr[i] > 0) {max_ending = max_ending * arr[i]; min_ending = min(min_ending *arr[i],1);   }
        else if(arr[i] ==  0 ) {max_ending = 1;min_ending = 1;len = 0;}
        else{int temp = max_ending;max_ending = max(min_ending * arr[i],1); min_ending = temp * arr[i];}
        if(product < max_ending){ product = max_ending;len++;last_index = i;}

    }
    cout << "Maximum product is : " << product  <<"\t";
    for (int j = last_index - len ; j <= last_index; ++j) cout << arr[j] <<" ";

}


// main function
int main()
{
    int arr[] =  { 1, -2, -3, 0, 7, -8, -2 };
    LargestProductContiguousSubarray(arr);

    return 0;
}
