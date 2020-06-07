#include<iostream>
#include <unordered_map>
#include <climits>
#include <vector>
using namespace std;


int knapSackRecursion(int v[],int w[],int n,int capacity,vector<int> &vec){
    if(n < 0 || capacity == 0) return 0;
    if(w[n] > capacity) return knapSackRecursion(v,w,n-1,capacity,vec);
    else{
        int preincludesize = vec.size();
        int include = v[n] + knapSackRecursion(v,w,n-1,capacity - w[n],vec);
        int preexcludesize = vec.size();
        int exclude = knapSackRecursion(v,w,n-1,capacity,vec);
        if(include > exclude){
            if(vec.size() > preexcludesize) vec.erase(vec.begin()+preexcludesize,vec.begin() + vec.size());
            vec.push_back(v[n]);
            return include;
        }
        else{
            if(preexcludesize > preincludesize) vec.erase(vec.begin()+preincludesize,vec.begin()+preexcludesize);
            return exclude;
        }
    }
}
unordered_map<string,int> lookup;

int knapSackMemoization(int v[],int w[],int n,int capacity,vector<int> & vec){
    if(n < 0 || capacity == 0) return  0;

    string key = to_string(n) + "|" + to_string(capacity);

    if(lookup.find(key) == lookup.end()){

        if(w[n] > capacity) lookup[key] =  knapSackMemoization(v,w,n-1,capacity,vec);
        else{
            int preIncludeSize = vec.size();
            int include = v[n] + knapSackMemoization(v,w,n-1,capacity - w[n],vec);

            int preExcludeSize = vec.size();
            int exclude = knapSackMemoization(v,w,n-1,capacity,vec);


            if(include > exclude){
                if(vec.size() > preExcludeSize) vec.erase(vec.begin() + preExcludeSize,vec.begin() + vec.size());
                vec.push_back(v[n]);
                lookup[key] = include;
            }
            else{
                if(preExcludeSize > preIncludeSize) vec.erase(vec.begin()+preIncludeSize,vec.begin()+preExcludeSize);
                lookup[key] =  exclude;
            }
        }
    }
    return lookup[key];
}

void knapSackTabulisation(int v[],int w[],int n,int capacity){
    int lookup[n +1][capacity + 1];
    for (int i = 0; i <= n ; ++i) {
        for (int j = 0; j <= capacity ; ++j) {
            if(i == 0 || j ==0) lookup[i][j] = 0;
            else if(w[i-1] > j) lookup[i][j] = lookup[i-1][j];
            else lookup[i][j] = max(lookup[i-1][j],v[i -1] + lookup[i-1][j - w[i-1]]);
        }
    }


    cout<<"Knapsack value is "<<lookup[n][capacity]<<endl;

    int result = lookup[n][capacity];
    int  cap = capacity;

    for (int i = n; i > 0 && result > 0 ; i--) {
        if(result == lookup[i - 1][cap]) continue;
        else{
            cout<<v[i - 1]<<" ";
            result = result - v[i -1];
            cap = cap - w[i - 1];
        }
    }

}

int main()
{
    int v[] = { 20, 5, 10, 40, 15, 25 };
    int w[] = {  1, 2,  3,  8,  7, 4 };
    int W = 10;
    int n = sizeof(v) / sizeof(v[0]);
    vector<int> vec;
    cout << "Knapsack value is " << knapSackRecursion(v, w, n - 1, W,vec)<<endl;
    for(auto i : vec) cout<<i<<" "; cout<<endl;

    vec.clear();
    cout << "Knapsack value is " << knapSackMemoization(v, w, n - 1, W,vec)<<endl;
    for(auto i : vec) cout<<i<<" "; cout<<endl;

    knapSackTabulisation(v,w,n,W);
    return 0;
}