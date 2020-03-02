#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nOW(int n) {
    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;
    // if(n == 3) return 4;
    return nOW(n - 1) + nOW(n - 2) + nOW(n - 3);
}

int nOWDP(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[ i - 2] + dp[i - 3];
    } return dp[n];
}

int main() {
    cout << nOW(5);
    cout << nOWDP(5);
    return 0;
}