#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n, int& maxWeightUsed) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i-1] <= w) {
                if (dp[i-1][w-wt[i-1]] + val[i-1] > dp[i-1][w]) {
                    dp[i][w] = dp[i-1][w-wt[i-1]] + val[i-1];
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    maxWeightUsed = 0;
    for (int w = 0; w <= W; ++w) {
        if (dp[n][w] == dp[n][W]) {
            maxWeightUsed = w;
            break;
        }
    }
    return dp[n][W];
}
int main() {
    int W, n, maxWeightUsed;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> wt(n), val(n);
    cout << "Enter the weights and values of the items:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> wt[i];
        cout << "Item " << i + 1 << " - Value: ";
        cin >> val[i];
    }
    int maxValue = knapsack(W, wt, val, n, maxWeightUsed);
    cout << "The maximum value that can be achieved is " << maxValue << endl;
    cout << "The maximum weight used to achieve this value is " << maxWeightUsed << endl;
    return 0;
}
