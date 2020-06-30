#include <iostream>
#include <unordered_map>
#include <climits>
#include <cstring>
#include <vector>
#define N 5
using namespace std;




typedef pair<int,int> Point;
Point tail;
int lookup[N][N];

void  constructPathTabulisation(int lookup[N][N],int grid[N][N],Point tail){
    vector<Point> path;
    path.push_back(tail);

    int i = tail.first;
    int j = tail.second;

    while(lookup[i][j]){
        if(i - 1 >= 0 && lookup[i][j] - lookup[i-1][j] == 1 && abs(grid[i-1][j] - grid[i][j]) == 1) path.push_back(make_pair(i-- - 1, j));
        else if(j - 1 >= 0 && lookup[i][j] - lookup[i][j-1] == 1 && abs(grid[i][j-1] - grid[i][j]) == 1) path.push_back(make_pair(i,j-- - 1));
    }

    for(auto it = path.rbegin() ; it != path.rend() ; it++) cout<< grid[it->first][it->second]<<" ";
}

int maxLengthSnakeSequenceTabulisation(int grid[N][N]){

    memset(lookup,0,sizeof lookup);

    int max_so_far = 0;


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(i - 1 >= 0 && abs(grid[i-1][j] - grid[i][j]) == 1){
                lookup[i][j] = lookup[i-1][j] + 1;
                if(max_so_far < lookup[i][j]){
                    max_so_far = lookup[i][j];
                    tail = make_pair(i,j);
                }
            }
            if(j - 1 >= 0 && abs(grid[i][j-1] - grid[i][j]) == 1){
                lookup[i][j] = lookup[i][j-1] + 1;
                if(max_so_far < lookup[i][j]){
                    max_so_far = lookup[i][j];
                    tail = make_pair(i,j);
                }
            }
        }
    }
    return lookup[N-1][N-1];
}

int main(void)
{
    int grid[N][N] =
            {
                    { 7, 5, 2, 3, 1 },
                    { 3, 4, 1, 4, 4 },
                    { 1, 5, 6, 7, 8 },
                    { 3, 4, 5, 8, 9 },
                    { 3, 2, 2, 7, 6 }
            };





    int len = maxLengthSnakeSequenceTabulisation(grid);
    cout<<"length of Longest snake is : " <<len<<endl;
    constructPathTabulisation(lookup,grid,tail);

    return 0;
}