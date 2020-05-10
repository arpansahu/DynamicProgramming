#include <iostream>
#include<vector>
#include <limits.h>


using namespace std;

template<size_t  n>
void Knapsack0_1(int (&WeightArray)[n], int (&ProfitArray)[n], int Capacity)
{
    int arr[n+1][Capacity + 1];
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= Capacity; ++w) {
            if(i ==0 || w == 0) arr[i][w] = 0;
            else if(WeightArray[i - 1] <= w ) arr[i][w] = max(arr[i - 1][w], arr[i - 1][w - WeightArray[i - 1]] + ProfitArray[i - 1]);
            else arr[i][w] = arr[i-1][w];

        }
    }

    cout <<arr[n][Capacity] <<"\n";
    int result = arr[n][Capacity];

    //printing the elements which were taken into bag

    for (int j = n; j >0 &&  result > 0 ; j--) {
        if(result == arr[j-1][Capacity]) continue;
        else{
            cout << WeightArray[j - 1] <<" ";
            result -= ProfitArray[j - 1];
            Capacity -= WeightArray[j-1];
        }

    }

}


// main function
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    Knapsack0_1(wt,val,W);

    return 0;
}
