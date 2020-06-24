#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

#include <algorithm>
#define M 3
#define N 3

using namespace std;

bool isSafe(int x,int y){
    if(x<0 || y < 0 || x >= 3 || y >= 3) return false;
    return true;
}

int totalWaysRecursiveUtil(int x,int y,int k,int isCol){
    if(k == -1 || !isSafe(x,y)) return 0;
    if(k == 0 && x == M-1 && y == N-1) return 1;
    if(isCol) return totalWaysRecursiveUtil(x+1,y,k,isCol) + totalWaysRecursiveUtil(x,y+1,k-1,!isCol);
    return totalWaysRecursiveUtil(x+1,y,k-1,!isCol) + totalWaysRecursiveUtil(x,y+1,k,isCol);
}

int totalWaysRecursive(int x,int y,int k){
    return totalWaysRecursiveUtil(x+1,y,k,1) + totalWaysRecursiveUtil(x,y+1,k,0);
}



int main(void)
{
    int k = 2;
    cout << "Total number of ways is " << totalWaysRecursive(0, 0, k)<<endl;

    return 0;
}
