#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <climits>
#define M 3
#define N 3

using namespace std;

int countPathsRecursive(int x,int y){
    if (x == M-1 || y == N-1) return 1;
    return countPathsRecursive(x+1,y) + countPathsRecursive(x,y+1);
}
unordered_map<string,int> lookup;

int countPathsMemoization(int x,int y){
    if (x == M-1 || y == N-1) return 1;
    string key  = to_string(x) + "|" + to_string(y);

    if(lookup.find(key) == lookup.end())    lookup[key] =  countPathsRecursive(x+1,y) + countPathsRecursive(x,y+1);

    return lookup[key];
}

int countPathsTabulisation(int m,int n){
    int lookup[m][n];

    for (int i = 0; i < m; i++)lookup[i][0] = 1;
    for (int j = 0; j < n; j++)lookup[0][j] = 1;


    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            lookup[i][j] = lookup[i - 1][j] + lookup[i][j - 1];
        }
    }
    
    return lookup[m - 1][n - 1];
}

int main(void)
{

    printf("Total number of paths are: %d\n", countPathsRecursive(0, 0));
    printf("Total number of paths are: %d\n", countPathsMemoization(0,0));
    printf("Total number of paths are: %d\n", countPathsTabulisation(M,N));
    return 0;
}