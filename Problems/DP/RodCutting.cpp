#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int rodCut(int n, int price[]) {
    if(n <= 0) return 0;
    int res = INT_MIN;
    for(int i = 0; i < n; i++) {
        res = max(res, price[i] + rodCut(n - (i+1), price));
    } return res; 
}

int rodCutDP(int n, int price[]) {
    int dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = INT_MIN;
        for(int j = 0; j < i; j++) {
            dp[i] = max(dp[i], price[j] + dp[i - (j+1)]);
        }
    } return dp[n];
}


int main() {
    // int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int price[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int len = sizeof(price)/sizeof(price[0]);
    cout << rodCut(len, price);
    cout << rodCutDP(len, price);
    return 0;
}