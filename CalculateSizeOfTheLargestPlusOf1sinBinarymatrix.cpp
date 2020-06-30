#include <iostream>
#include <cstring>
#define N 10
using namespace std;

int calculateSize(int grid[N][N]){
    int max_So_Far = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {

            if(grid[i][j] == 1 && i-1 >= 0 && i <= N-1 && j-1 >= 0 && j <= N-1) {
                int tempcount = 0;
                int top_x = i -1;
                int top_y = j;
                int down_x = i + 1;
                int down_y = j;
                int left_x = i;
                int left_y = j-1;
                int right_x = i;
                int right_y = j+1;

                while(grid[i-1][j]  && grid[i+1][j] && grid[i][j+1] && grid[i][j-1]) {
                    tempcount++;
                    top_x--;
                    down_x++;
                    left_y--;
                    right_y++;
                    if(top_x < 0 || down_x >= N || left_y < 0 || right_y >= N) break;
                }

                if(tempcount > max_So_Far) max_So_Far = tempcount;
            }

        }
    }

    return max_So_Far;
}


int calculateSizeTabulisation(int grid[N][N]){
    int leftlookup[N][N],rightlookup[N][N],toplookup[N][N],downlookup[N][N];
    memset(leftlookup,0,sizeof leftlookup);
    memset(rightlookup,0,sizeof rightlookup);
    memset(toplookup,0,sizeof toplookup);
    memset(downlookup,0,sizeof downlookup);

    for (int i = 0; i <  N; ++i) {
        toplookup[0][i] = grid[0][i];
        downlookup[N-1][i] = grid[N-1][i];
        leftlookup[i][0] = grid[i][0];
        rightlookup[i][N-1] = grid[i][N-1];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (grid[i][j] == 1)leftlookup[i][j] = leftlookup[i][j - 1] + 1;
            if (grid[j][i] == 1)toplookup[j][i] = toplookup[j - 1][i] + 1;
            if (grid[N - 1 - j][i] == 1)downlookup[N - 1 - j][i] = downlookup[N - j][i] + 1;
            if (grid[i][N - 1 - j] == 1)rightlookup[i][N - 1 - j] = rightlookup[i][N - j] + 1;
        }
    }

    int bar = 0;

    for (int i = 0; i <  N; ++i) {
        for (int j = 0; j < N; ++j) {
            int len = min(toplookup[i][j] , min(downlookup[i][j],min(leftlookup[i][j],rightlookup[i][j])));
            if(len -1 > bar) bar = len -1 ;
        }
    }
    return bar;
}


int main()
{
    int grid[N][N] =
            {
                    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                    { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                    { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                    { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
                    { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
                    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                    { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
                    { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
                    { 1, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
                    { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
            };

    int bar = calculateSize(grid);
    int bartab = calculateSizeTabulisation(grid);
    if (bar)    printf("Largest Plus of 1's has size of %d\n", 4*bar + 1);
    if (bartab)    printf("Largest Plus of 1's has size of %d\n", 4*bartab + 1);

    return 0;
}