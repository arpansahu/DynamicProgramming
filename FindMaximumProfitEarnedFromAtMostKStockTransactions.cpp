#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> price, int k)
{
    int n = price.size();
    int lookup[k+1][n];

    for (int i = 0; i <= k ; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == 0 || j == 0) lookup[i][j] = 0;
            else {
                int max_so_far = 0;
                for (int k = 0; k < j ; ++k) {
                    int curr_price = price[j] - price[k] + lookup[i-1][k];
                    if(max_so_far < curr_price) max_so_far = curr_price;
                }
                lookup[i][j] = max(lookup[i][j-1],max_so_far);
            }
        }
    }
    return lookup[k][n-1];
}

int maxProfitOptimised(vector<int> price, int k)
{
    int n = price.size();
    int lookup[k+1][n+1];

    for (int i = 0; i <= k ; ++i) {
        int prev_diff = INT_MIN;

        for (int j = 0; j < n; ++j) {
            if(i == 0 || j == 0) lookup[i][j] = 0;
            else {
                prev_diff = max(prev_diff,lookup[i-1][j-1] - price[j-1]);
                lookup[i][j] = max(lookup[i][j-1],price[j] + prev_diff);
            }
        }
    }
    return lookup[k][n-1];
}

int main()
{
    vector<int> price { 1, 5, 2, 3, 7, 6, 4, 5 };
    int k = 3;

    cout << "The maximum possible profit is: " << maxProfit(price, k)<<endl;
    cout << "The maximum possible profit is: " << maxProfitOptimised(price, k);

    return 0;
}