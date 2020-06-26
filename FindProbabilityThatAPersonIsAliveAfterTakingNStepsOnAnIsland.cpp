#include <iostream>
#include <unordered_map>
#include <climits>
#include <cstring>
#define SIZEOFMATRIX 3
using namespace std;

int row[] = {-1,1,0,0};
int col[] = {0,0,1,-1};

int isSafe(int x,int y){
    if(x < 0 || y < 0 || x > SIZEOFMATRIX - 1 || y > SIZEOFMATRIX -1) return false;
    return true;
}

float aliveProbabilityRecursive(int x,int y,int n){
    if(n == 0) return 1.0;
    float probability = 0.0;
    for (int i = 0; i < 4; ++i) {
        if(isSafe(x+row[i],y+col[i]))probability += 0.25 * aliveProbabilityRecursive(x + row[i], y + col[i], n - 1);
    }
    return probability;
}

unordered_map<string,float> lookup;

float aliveProbabilityMemoization(int x,int y,int n){
    if(n == 0) return 1.0;

    string key = to_string(x) + "|" + to_string(y) + "|" + to_string(n);

    if(lookup.find(key) == lookup.end()){
        float probability = 0.0;
        for (int i = 0; i < 4; ++i) {
            if(isSafe(x+row[i],y+col[i]))probability += 0.25 * aliveProbabilityMemoization(x + row[i], y + col[i], n - 1);
        }
        lookup[key] =  probability;
    }
    return lookup[key];
}



int main(void)
{
    int n = 3;
    int x = 0, y = 0;
    cout << "Alive probability is " << aliveProbabilityRecursive(x, y, n)<<endl;
    cout << "Alive probability is " << aliveProbabilityMemoization(x, y, n)<<endl;
    return 0;
}