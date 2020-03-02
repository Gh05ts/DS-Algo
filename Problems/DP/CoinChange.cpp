#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// have unlimited coins with n1, n2, n3 values add to N
int coinChangeRec(int N, int ar[], int i) {
    if(N < 0) return 0;
    if(N == 0) return 1;
    if(i <= 0 && N > 0) return 0;
    return coinChangeRec(N - ar[i], ar, i) + coinChangeRec(N, ar, i - 1);
}

int coinChangeDP(int Sum, int ar[], int len) {
    int dp[len + 1][Sum + 1];
    for(int i = 0; i <= Sum; i++) dp[0][i] = 0;
    for(int j = 0; j <= len; j++) dp[j][0] = 1;
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= Sum; j++) {
            if(j - ar[i] >= 0) dp[i][j] = dp[i - 1][j] + dp[i][j - ar[i]];
            else dp[i][j] = dp[i - 1][j];
        } 
    } return dp[len][Sum];
}

int main() {
    int N = 8;
    int ar[] = {1, 2, 3, 4};
    int len = sizeof(ar)/sizeof(ar[0]);
    // cout << coinChangeRec(N, ar, len);
    cout << coinChangeDP(N, ar, len);
    return 0;
}