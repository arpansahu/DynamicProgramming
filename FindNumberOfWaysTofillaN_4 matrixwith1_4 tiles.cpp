#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

int totalWaysRecusrive(int n ){
    if(n < 1) return 0;
    else if(n <  4) return 1;
    else if(n == 4) return 2;
    else if (n > 4) return totalWaysRecusrive(n-1) + totalWaysRecusrive(n-4);
}
unordered_map <string,int> lookup;

int totalWaysMemoization(int n ){
    if(n < 1) return 0;
    else if(n <  4) return 1;
    else if(n == 4) return 2;
    string key = to_string(n);
    if(lookup.find(key) == lookup.end())    lookup[key] = totalWaysMemoization(n - 1) + totalWaysMemoization(n - 4);
    return lookup[key] ;
}

int totalWaysTabulisation(int n ){
    int lookup[n+1];

    for (int i = 0; i <= n; ++i) {
        if(i < 1) lookup[i] = 0;
        else if(i == 4) lookup[i] = 2;
        else if(i < 4) lookup[i] = 1;
        else lookup[i] = lookup[i-1] + lookup[i-4];
    }

    return lookup[n] ;
}

int main(void)
{
    int n = 5;

    printf("Total number of ways are %d\n", totalWaysRecusrive(n));
    printf("Total number of ways are %d\n", totalWaysMemoization(n));
    printf("Total number of ways are %d\n", totalWaysTabulisation(n));

    return 0;
}
