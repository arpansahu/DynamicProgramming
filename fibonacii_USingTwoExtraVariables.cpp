#include<iostream>
using namespace std;

int fibonacii(int n){
    int prev = 0,curr = 1;

    for (int i = 0; i < n -1 ; ++i) {
        int newcurr = curr + prev;
        prev = curr;
        curr = newcurr;
    }
    return curr;
}

int main(){
    cout << fibonacii(8);
    return 0;

}