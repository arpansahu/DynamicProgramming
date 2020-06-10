#include<iostream>
#include <climits>

using namespace std;

int rodCut(int price[],int n){
    if(n == 0 ) return 0;
    int maxVal = INT_MIN;
    for (int i = 1; i <= n ; ++i) {
        int cost  = price[i-1] + rodCut(price,n- i);
        if(cost > maxVal) maxVal = cost;
    }
    return maxVal;
}

int rodCutTabulisation(int price[],int n){
    int lookup[n+1];
    for (int i = 0; i <= n ; ++i) lookup[i] = 0;
    for (int i = 1; i <= n ; ++i) for (int j = 1; j <= i ; ++j)  lookup[i] = max(lookup[i] , price[j-1]+lookup[i-j]);
    return lookup[n];
}

int main()
{
    int length[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int price [] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = 4;

    cout << "Profit is " << rodCut(price, n)<<endl;
    cout << "Profit is " << rodCutTabulisation(price, n);

    return 0;

}