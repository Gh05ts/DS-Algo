#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int knapsackRec(int n, int W, int val[], int wt[]) {
    if(n == 0 || W == 0) return 0;
    if(wt[n - 1] > W) return knapsackRec(n - 1, W, val, wt);
    else return max(val[n - 1] + knapsackRec(n - 1, W - wt[n - 1], val, wt), knapsackRec(n - 1, W, val, wt)); 
}

int knapsackDP(int n, int W, int val[], int wt[]) {
    int i, w;
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for(i = 0; i <= n; i++) {
        for(w = 0; w <= W; w++) {
            if(i == 0 || w == 0) dp[i][w] = 0;
            else if(wt[i - 1] <= w) dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else dp[i][w] = dp[i - 1][w];
            // cout << dp[i][w];
        } // cout << endl;
    } return dp[n][W];
}

int main() {
    int val[] = {3, 45, 23, 62, 23};
    int wt[] = {13, 31, 43, 34, 23};
    int W = 80;
    int n = sizeof(val)/sizeof(val[0]);
    cout << knapsackRec(n, W, val, wt);
    cout << knapsackDP(n, W, val, wt);

    return 0;
}