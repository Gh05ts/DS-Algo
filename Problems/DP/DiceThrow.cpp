#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int diceThrowRec(int n, int m, int sum) {
    if(sum == 0 && n == 0) return 1;
    if(n < 1 && sum > 0) return 0;
    if(sum < 0) return 0;
    int res = 0;
    for(int i = 1; i <= m; i++) {
        res += diceThrowRec(n - 1, m, sum - i);
    } return res;
}

int diceThrowDP(int n, int m, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for(int i = 1; i <= min(m, sum); i++) dp[1][i]++;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            for(int x = 1; x <= m && j - x >= 0 ; x++) dp[i][j] += dp[i - 1][j - x];  
        }
    } return dp[n][sum];
}

int main() {
    int n = 3;
    int m = 6;
    int sum = 12;
    cout << diceThrowRec(n, m, sum);
    cout << diceThrowDP(n, m, sum);
    return 0;
}

