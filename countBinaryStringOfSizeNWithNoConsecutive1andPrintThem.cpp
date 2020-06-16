#include<iostream>
#include <unordered_map>
using namespace std;

int countStringsRecursive(int n, int lastDigit){
    if(n <= 0) return 0;
    if(n == 1){
        if(lastDigit) return 1;
        else return 2;
    }
    if (lastDigit == 0) return  countStringsRecursive(n-1,1) + countStringsRecursive(n-1,0);
    else return countStringsRecursive(n-1,0);
}
unordered_map<string,int> lookup;
int countStringMemoizzation(int n ,int lastDigit){
    if(n <= 0) return 0;
    if(n == 1){
        if(lastDigit) return  1;
        else return 2;
    }
    string key  = to_string(n) + "|" + to_string(lastDigit);
    if(lookup.find(key) == lookup.end()){
        if(lastDigit) lookup[key] =  countStringMemoizzation(n-1,0);
        else lookup[key] =  countStringMemoizzation(n-1,0) + countStringMemoizzation(n-1,1);
    }
    return lookup[key];
}

int countStringTabulisation(int n){
    int lookup[n+1][2];
    lookup[0][0] = 0;
    lookup[0][1] = 0;
    lookup[1][0] = 2;
    lookup[1][1] = 1;
    for (int i = 2; i <= n ; ++i) {
        lookup[i][0] = lookup[i-1][0] + lookup[i-1][1];
        lookup[i][1] = lookup[i-1][0];
    }
    return lookup[n][0];
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
    cout << "Number of " << n << "-digit binary strings without any consecutive 1's are " << countStringsRecursive(n, 0)<<endl;
    cout << "Number of " << n << "-digit binary strings without any consecutive 1's are " << countStringMemoizzation(n, 0)<<endl;
    cout << "Number of " << n << "-digit binary strings without any consecutive 1's are " << countStringTabulisation(n)<<endl;
    printStrings(n,0,"");
    return 0;
}