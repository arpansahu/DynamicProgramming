#include<iostream>
#include <climits>

using namespace std;

int rodCut(int n){
    if(n <= 0 ) return 0;
    int maxVal = n;
    for (int i = 1; i <= n ; ++i) maxVal = max(maxVal,i*rodCut(n-i));

    return maxVal;
}

int rodCutTabulisation(int n){
    int lookup[n+1];
    for (int i = 0; i <= n ; ++i) lookup[i] = i;
    for (int i = 1; i <= n ; ++i) for (int j = 1; j <= i ; ++j)  lookup[i] = max(lookup[i] , j * lookup[i-j]);
    return lookup[n];
}

int main()
{

    int n = 4;

    cout << "Profit is " << rodCut(n)<<endl;
    cout << "Profit is " << rodCutTabulisation(n);

    return 0;

}