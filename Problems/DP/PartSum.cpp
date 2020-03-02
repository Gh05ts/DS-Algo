#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool partitionHelper(int ar[], int len, int sum) {
    if(sum == 0) return true;
    if(sum > 0 && len == 0) return false;
    if(ar[len - 1] > sum) return partitionHelper(ar, len - 1, sum);
    return partitionHelper(ar, len - 1, sum) || partitionHelper(ar, len - 1, sum - ar[len - 1]);
}

bool partition(int ar[], int len) {
    int sum = accumulate(ar, ar+len, 0);
    if(sum % 2 != 0) return false;
    return partitionHelper(ar, len, sum);
}

bool partitionDP(int ar[], int len) {
    int sum = accumulate(ar, ar + len, 0);
    if(sum % 2 != 0) return false;
    int dp[len + 1][sum/2 + 1];
    for(int i = 0; i <= sum/2; i++) dp[0][i] = false;
    for(int i = 0; i <= len; i++) dp[i][0] = true;
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= sum/2; j++) {
            if(j - ar[i] >= 0) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - ar[i]];
            else dp[i][j] = dp[i - 1][j];
        }
    } return dp[len][sum/2];
}

int main() {
    int ar[] = {1, 5, 11, 5};
    // int ar[] = {3, 1, 1, 2, 2, 1};
    int len = sizeof(ar)/sizeof(ar[0]);
    cout << partition(ar, len);
    cout << partitionDP(ar, len);
    return 0;
}