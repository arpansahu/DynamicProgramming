#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int totalWaysRecursive(int n,int m){
    if(n < 0) return 0;
    if(n ==0) return 1;
    int count = 0;
    for (int i = 1; i <= m ; ++i) count += totalWaysRecursive(n-i,m);

    return count;
}


int totalWaysMemoization(int n,int m,vector<int> &lookup){
    if(n < 0) return 0;
    if(n ==0) return 1;

    if(lookup[n] == 0)
    for (int i = 1; i <= m ; ++i) lookup[n] += totalWaysMemoization(n-i,m,lookup);

    return lookup[n];
}

int totalWaysTabulisation(int n,int m){

    int lookup[n+1];

    lookup[0] = 1;
    lookup[1] = 1;
    lookup[2] = 2;

    for (int i = 3; i <= n ; ++i) {
        lookup[i] = 0;
        for (int j = 1; j <= m && (i-j) >= 0 ; ++j) lookup[i] += lookup[i-j];
    }
    return lookup[n];
}
int main(void)
{
    int n = 4, m = 3;
    printf("Total ways to reach the %d'th stair with at-most %d steps are %d",n, m, totalWaysRecursive(n, m));cout<<endl;
    vector<int> lookup(n+1);
    printf("Total ways to reach the %d'th stair with at-most %d steps are %d",n, m, totalWaysMemoization(n, m,lookup));cout<<endl;
    printf("Total ways to reach the %d'th stair with at-most %d steps are %d",n, m, totalWaysTabulisation(n, m));cout<<endl;


    return 0;
}
