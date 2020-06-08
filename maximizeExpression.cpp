#include <iostream>


using namespace std;

int maximizeExpression(int arr[],int size)
{
    int p = 0,q = 0,r = 0,s = 0;
    int temp = arr[0];
    for (int i = 1; i < size; ++i)
        if(temp < arr[i])
        {
            temp = arr[i];
            p = i;
        }
    temp = arr[0];
    for (int i = 1; i < p; ++i) {
        if(temp > arr[i])
        {
            temp = arr[i];
            q = i;
        }
    }
    temp = arr[0];
    for (int i = 1; i < q; ++i)
        if(temp < arr[i])
        {
            temp = arr[i];
            r = i;
        }
    temp = arr[0];
    for (int i = 1; i < r; ++i) {
        if(temp > arr[i])
        {
            temp = arr[i];
            s = i;
        }
    }

    return arr[p]  - arr[q] + arr[r] - arr[s];

}


// main function
int main()
{
    int A[] = { 3, 9, 10, 1, 30, 40 };
    int n = sizeof(A) / sizeof(A[0]);

    if (n >= 4) cout << maximizeExpression(A, n);

    return 0;
}
