#include <iostream>
#include<vector>
#include <limits.h>


using namespace std;

template<size_t  n>
void LargestSumContiguousSubarray(int (&arr)[n])
{
    int sum = INT_MIN;
    int tempsum  = 0;
    int last_index = 0;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        tempsum += arr[i];
        if(sum < tempsum) {sum = tempsum;len = i - last_index ;last_index = i;}
        if(tempsum < 0 )tempsum = 0;//cout << sum <<" " << tempsum <<"\n";
    }
    cout << "Maximum sum is :" <<sum <<"\t";
    for (int j = last_index - len ; j <= last_index; ++j) cout << arr[j] <<" ";

}


// main function
int main()
{
    int arr[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
    LargestSumContiguousSubarray(arr);

    return 0;
}
