#include<iostream>
#include <unordered_map>
using namespace std;

int countStringsRecursive(int n,int lastDigit){
    if(n == 0) return 0;
    if(n == 1){
        if(lastDigit) return 1;
        else return 2;
    }
    if(lastDigit == 0) return countStringsRecursive(n-1,1) + countStringsRecursive(n-1,0);
    else countStringsRecursive(n-1,0);
}

unordered_map<string,int> lookup;

int countStringsMemoization(int n,int lastDigit){
    if(n == 0) return 0;
    if(n == 1) {if(lastDigit) return 1; else return 2;}
    string key  = to_string(n) + "|" + to_string(lastDigit);
    if(lookup.find(key) == lookup.end()){
        if(lastDigit == 0) lookup[key] = countStringsMemoization(n-1,0) + countStringsMemoization(n-1,1);
        else lookup[key] = countStringsMemoization(n-1,0);
    }
    return lookup[key];
}

void printStrings(int n ,int lastDigits,string str){
    if(n == 0) {
        cout<<str<<endl;
        return ;
    }
    if(lastDigits == 0) {


        printStrings(n-1,0,str + to_string(0));
        printStrings(n-1,1,str + to_string(1));
    }
    else printStrings(n-1,0,str+to_string(0));
}
int main()
{
    int n = 5;

    cout << "Number of " << n << "-digit binary strings without any consecutive 1's are " << countStringsRecursive(n, 0)<<"\n";
    cout << "Number of " << n << "-digit binary strings without any consecutive 1's are " << countStringsMemoization(n, 0)<<"\n";
    printStrings(n,0,"");
    return 0;

}