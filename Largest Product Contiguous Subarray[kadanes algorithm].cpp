#include <iostream>
#include<vector>
#include <limits.h>


using namespace std;

template<size_t  n>
void LargestProductContiguousSubarray(int (&arr)[n])
{
    int max_product_so_far = 0;
    int max_ending_here  = 1;
    int min_ending_here = 1;


    int last_index = 0;
    int len = 0;


    for (int i = 0; i < n; ++i) {

        if(arr[i] > 0) {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(min_ending_here * arr[i], 1);
        }
        else if(arr[i] ==  0 ) {
            max_ending_here = 1;min_ending_here = 1;len = 0;
        }
        else{
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }

        if(max_product_so_far < max_ending_here){
            max_product_so_far = max_ending_here;
            len++;
            last_index = i;
        }

    }
    cout << "Maximum max_product_so_far is : " << max_product_so_far << "\t";
    for (int j = last_index - len ; j <= last_index; ++j) cout << arr[j] <<" ";

}


// main function
int main()
{
    int arr[] =  { 1, -2, -3, 0, 7, -8, -2 };
    LargestProductContiguousSubarray(arr);

    return 0;
}
