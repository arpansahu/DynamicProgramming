#include <iostream>
using namespace std;

bool subsetSumrecursive(int arr[],int size,int sum){
    if(size == 0) return true;

    if(size  < 0  || sum < 0) return false;

    bool include = subsetSumrecursive(arr,size -1,sum - arr[size]);
    if(include) return true;

    bool exclude = subsetSumrecursive(arr,size-1,sum);
    return exclude;
}

bool partitionR(int arr[],int size)
{
    int sum = 0;
    for (int i = 0; i < size ; ++i) sum += arr[i];

    if(sum % 2 != 0) return false;
    else return subsetSumrecursive(arr,size - 1,sum/2);
}

bool subSetTabulisation(int arr[],int size,int sum){
    int lookup[size+1][sum+1];
    for (int i = 0; i <= size ; ++i) {
        for (int j = 0; j <= sum ; ++j) {
            if(i == 0 || j == 0) lookup[i][j] = 0;
            if(arr[i-1] > j) lookup[i][j] = lookup[i-1][j];
            else lookup[i][j] = lookup[i-1][j] || lookup[i-1][j - arr[i-1]];
        }
    }
    return lookup[size][sum];
}

bool PartitionTabulisation(int arr[],int size)
{
    int sum = 0;
    for (int i = 0; i < size ; ++i) sum += arr[i];

    if(sum % 2 != 0) return false;
    else return subSetTabulisation(arr,size - 1,sum/2);
}
// main function
int main()
{
    int arr[] = { 7, 3, 1, 5, 4, 8 }; // remove 3 and answer will be no

    int n = (*(&arr + 1) - arr);

    if (partitionR(arr, n))
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;

    if (PartitionTabulisation(arr, n))
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;

    return 0;
}
