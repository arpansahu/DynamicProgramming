#include <iostream>
#include <unordered_map>
using namespace std;

bool subsetSumrecursive(int arr[],int size,int sum){
    if (sum == 0) return true;
    if(size < 0 || sum < 0) return false;

    bool include = subsetSumrecursive(arr,size -1,sum - arr[size]);
    bool exclude = subsetSumrecursive(arr,size-1,sum);
    return include || exclude;
}
unordered_map<string,int> lookup;
bool subsetMemoisation(int arr[],int size,int sum){
    if (sum == 0) return true;
    if(size < 0 || sum < 0) return false;

    string key  = to_string(size) + "|" + to_string(sum);
    if(lookup.find(key) == lookup.end()){
        bool include = subsetSumrecursive(arr,size -1,sum - arr[size]);
        bool exclude = subsetSumrecursive(arr,size-1,sum);
        lookup[key] =  include || exclude;
    }
    return lookup[key];
}

bool subsetTbulisation(int arr[],int size,int sum){
    int lookup[size +1][sum +1];
    for (int i = 0; i <= size ; ++i) {
        for (int j = 0; j <= sum ; ++j) {
            if( i == 0 || j == 0) lookup[i][j] = 0;
            if(arr[i-1] > j) lookup[i][j] = lookup[i-1][j];
            else lookup[i][j] = lookup[i-1][j] || lookup[i-1][j-arr[i-1]];
        }
    }
    return lookup[size][sum];
}

// main function
int main()
{
    int arr[] = { 7, 3, 2, 5, 8 };
    int sum = 14;
    int n = (*(&arr + 1) - arr);

    if (subsetSumrecursive(arr, n -1,sum))
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;

    if (subsetMemoisation(arr, n,sum))
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;

    if (subsetTbulisation(arr, n,sum))
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;


    return 0;
}
