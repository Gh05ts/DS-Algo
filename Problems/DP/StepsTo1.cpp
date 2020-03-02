#include <iostream>
using namespace std;

// Recursion solution
int countStepsTo1(int n) {
    if(n == 1) return 0;
    int res = countStepsTo1(n - 1);
    if(n % 2 == 0) {
        int res = min(res, countStepsTo1(n/2));
    }
    if(n % 3 == 0) {
        int res = min(res, countStepsTo1(n/3));
    }
    return res + 1;
}

// Memoization approach
int countStepsTo1Memo(int n, int arr[]) {
    if(n == 1) return 0;
    if(arr[n] != 0) {
        return arr[n];
    } 
    int res = countStepsTo1Memo(n - 1, arr);
    if(n % 2 == 0) {
        int res = min(res, countStepsTo1Memo(n/2, arr));
    }
    if(n % 3 == 0) {
        int res = min(res, countStepsTo1Memo(n/3, arr));
    } arr[n] = res + 1;
    return arr[n];
}

int countStepsTo12(int n) {
    int arr[n + 1];
    for(int i = 0; i <= n; i++) {
        arr[i] = 0;
    }
    return countStepsTo1Memo(n, arr);
}

// Bottom up/ DP approach

int countStepDP(int n) {
    int* dp = new int[n + 1];
    fill(dp, dp+n+1, n);
    return countStepsDPHelper(n, dp);
}

int countStepsDPHelper(int n, int dp[]) {
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {

    }
    return ;
}

int main() {
    // cout << countStepsTo12(100000);
    // cout << countStepsTo1(1000) << endl;
    countStepDP(5);
    return 0;
}