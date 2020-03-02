#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int eggDrop(int n, int h) {
    if(n == 1) return h;
    if(h == 0 || h == 1) return h;
    int res = INT_MAX;
    for(int i = 1; i <= h; i++) {
        res = min(res, (1 + max(eggDrop(n - 1, i - 1), eggDrop(n, h - i))));
    } return res;
}

int eggDropDP(int n, int h) {
    int dp[n + 1][h + 1];
    for(int i = 0; i <= h; i++) dp[0][i] = 0;
    for(int i = 1; i <= h; i++) dp[1][i] = i;
    for(int j = 1; j <= n; j++) dp[j][0] = 0;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= h; j++) {
            dp[i][j] = INT_MAX;
            for(int x = 1; x <= j; x++) dp[i][j] = min(dp[i][j], (1 + max(dp[i - 1][x - 1], dp[i][j - x])));
        }
    } return dp[n][h];
}


int main() {
    // cout << eggDrop(2, 100);
    cout << eggDropDP(2, 100);
    return 0;
}