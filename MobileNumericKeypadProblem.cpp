#include<iostream>
#include <unordered_map>
using namespace std;
#define N 3
#define M 4


bool check(char arr[M][N],int x ,int y){
    if(x < 0 || y < 0 || x >= M || y  >=  N || arr[x][y] == '*' || arr[x][y] == '#') return false;
    else return true ;
}

int countStringsRecursive(char arr[M][N],int n,int x,int y){
    if(!check(arr,x,y) || n <= 0) return 0;
    if(n == 1) return 1;
    return countStringsRecursive(arr,n-1,x,y) + countStringsRecursive(arr,n-1,x,y-1) + countStringsRecursive(arr,n-1,x-1,y) +countStringsRecursive(arr,n-1,x,y+1) + countStringsRecursive(arr,n-1,x+1,y);
}

int getCountRecursive(char arr[M][N],int n){
    int count = 0;
    for (int i = 0; i < M ; ++i) {
        for (int j = 0; j < N; ++j) {
            count += countStringsRecursive(arr,n,i,j);
        }
    }
    return count;
}
unordered_map<string,int> lookup;

int countStringsMemoziation(char arr[M][N],int n,int x,int y){
    if(!check(arr,x,y) || n <= 0) return 0;
    if(n == 1) return 1;
    string key = to_string(n) + "|" +  to_string(x) + "|" + to_string(y);
    if(lookup.find(key) == lookup.end()) lookup[key] = countStringsRecursive(arr,n-1,x,y) + countStringsRecursive(arr,n-1,x,y-1) + countStringsRecursive(arr,n-1,x-1,y) +countStringsRecursive(arr,n-1,x,y+1) + countStringsRecursive(arr,n-1,x+1,y);
    return lookup[key];
}

int getCountMemoization(char arr[M][N],int n){
    int count = 0;
    for (int i = 0; i < M ; ++i) {
        for (int j = 0; j < N; ++j) {
            count += countStringsMemoziation(arr,n,i,j);
        }
    }
    return count;
}

int getCountTabulisation(char arr[M][N], int n)
{
    if(arr == NULL || n <= 0)   return 0;
    if(n == 1)  return 10;

    int row[] = {0, 0, -1, 0, 1};
    int col[] = {0, -1, 0, 1, 0};


    int count[10][n+1];
    int i=0, j=0, k=0, move=0, ro=0, co=0, num = 0;
    int nextNum=0, totalCount = 0;

    for (i=0; i<=9; i++)
    {
        count[i][0] = 0;
        count[i][1] = 1;
    }


    for (k=2; k<=n; k++)
    {
        for (i=0; i<M; i++)
        {
            for (j=0; j<N; j++)
            {

                if (arr[i][j] != '*' && arr[i][j] != '#')
                {
                    num = arr[i][j] - '0';
                    count[num][k] = 0;

                    for (move=0; move<5; move++)
                    {
                        ro = i + row[move];
                        co = j + col[move];
                        if (check(arr,ro,co))
                        {
                            nextNum = arr[ro][co] - '0';
                            count[num][k] += count[nextNum][k-1];
                        }
                    }
                }
            }
        }
    }

    totalCount = 0;
    for (i=0; i<=9; i++)
        totalCount += count[i][n];
    return totalCount;
}

int row[] = {0, 0, -1, 0, 1};
int col[] = {0, -1, 0, 1, 0};

void printString(char arr[M][N],int x,int y,int n,string str){
    if(!check(arr,x,y) || n <= 0) return ;
    str = str  + arr[x][y] ;
    if(n == 1) cout << str<<" ";
    else
        for (int move = 0; move < 5; ++move) {
            printString(arr,x+row[move],y+col[move],n-1,str);
        }
}
int main()
{

    char key[M][N] =
            {
                    { '1', '2', '3' },
                    { '4', '5', '6' },
                    { '7', '8', '9' },
                    { '*', '0', '#' }
            };
    cout << "Count for numbers of length "<<1<<" "<< getCountRecursive(key, 1) <<endl;
    cout << "Count for numbers of length "<<2<<" "<< getCountRecursive(key, 2) <<endl;
    cout << "Count for numbers of length "<<3<<" "<< getCountRecursive(key, 3) <<endl;
    cout << "Count for numbers of length "<<4<<" "<< getCountRecursive(key, 4) <<endl;
    cout << "Count for numbers of length "<<5<<" "<< getCountRecursive(key, 5) <<endl<<endl<<endl;

    cout << "Count for numbers of length "<<1<<" "<< getCountMemoization(key, 1) <<endl;
    cout << "Count for numbers of length "<<2<<" "<< getCountMemoization(key, 2) <<endl;
    cout << "Count for numbers of length "<<3<<" "<< getCountMemoization(key, 3) <<endl;
    cout << "Count for numbers of length "<<4<<" "<< getCountMemoization(key, 4) <<endl;
    cout << "Count for numbers of length "<<5<<" "<< getCountMemoization(key, 5) <<endl<<endl<<endl;

    cout << "Count for numbers of length "<<1<<" "<< getCountTabulisation(key, 1) <<endl;
    cout << "Count for numbers of length "<<2<<" "<< getCountTabulisation(key, 2) <<endl;
    cout << "Count for numbers of length "<<3<<" "<< getCountTabulisation(key, 3) <<endl;
    cout << "Count for numbers of length "<<4<<" "<< getCountTabulisation(key, 4) <<endl;
    cout << "Count for numbers of length "<<5<<" "<< getCountTabulisation(key, 5) <<endl<<endl<<endl;

    for (int k = 1; k <= 5 ; ++k) {
        cout <<"For : k = "<< k<<"   ";
        for (int i = 0; i < M ; ++i) {
            for (int j = 0; j < N; ++j) {
                printString(key,i,j,k,"");
            }
        }
        cout<<endl<<endl<<endl;
    }

    return 0;
}