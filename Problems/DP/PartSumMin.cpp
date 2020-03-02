#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int pSumMinRec(int ar[], int len, int curSum, int totSum) {
    if(len == 0) return abs((totSum - curSum) - curSum);
    return min(pSumMinRec(ar, len - 1, curSum + ar[len - 1], totSum), pSumMinRec(ar, len - 1, curSum, totSum));
}


int pSumMin(int ar[], int len) {
    int sum = accumulate(ar, ar + len, 0);
    return pSumMinRec(ar, len, 0, sum);
}

int pSumMinDP(int ar[], int len) {
    int sum = accumulate(ar, ar + len, 0);
    int dp[len + 1][sum + 1];

}

int main() {
    int ar[] = {1, 6, 11, 5};
    int len = sizeof(ar)/sizeof(ar[0]);
    cout << pSumMin(ar, len);
    return 0;
}