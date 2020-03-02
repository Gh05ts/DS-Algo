#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxSum(int ar[], int len) {            // DP question/ Kadane's Algo
    // int dp[len + 1];
    int a = 0;
    int absMax = INT_MIN;
    for(int i = 1; i <= len; i++) {
        a = max(ar[i - 1], ar[i - 1] + a);
        if(a > absMax) absMax = a;          // absMax = max(a, absMax);
    } return absMax;
}

int main() {
    int ar[] = {23, 34, -34, -89, 3, 5, -3, 67, 3, -35, 8};
    int len = sizeof(ar)/sizeof(ar[0]);
    cout << maxSum(ar, len);
    return 0;
}