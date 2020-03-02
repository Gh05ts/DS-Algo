#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int optimalStrategyHelper(int n, int& sum, int nMax, int ar[], int i, bool flag) {
//     if(n <= nMax / 2 || i >= nMax / 2) 
//     if(flag) {
//         flag = false;
//         min(optimalStrategyHelper(n - 1, sum, nMax, ar, i, flag),
//         optimalStrategyHelper(n, sum, nMax, ar, i + 1, flag));
//     } 
//     flag = true;
//     sum += ar[i];
//     optimalStrategyHelper(n, sum, nMax, ar, i + 1, flag);
//     int temp = ar[i];
//     sum -= temp;
//     sum += ar[n - 1];
//     optimalStrategyHelper(n - 1, sum, nMax, ar, i, flag);
//     return max(temp, sum);
// }

// int optimalStrategy(int n, int ar[]) { 
//     int sum = 0;
//     int i = 0;
//     bool flag = false;
//     return optimalStrategyHelper(n, sum, n, ar, i, flag);
// }

int optimalStrategyRec(int a[], int i, int j) {
	if (i == j) return 0; // last element is selected by opponent, so user gets nothing
	int turn = (j - i + 1) % 2;
	if (turn == 0) return max(a[i] + optimalStrategyRec(a, i + 1, j), a[j] + optimalStrategyRec(a, i, j - 1));
	else return min(optimalStrategyRec(a, i + 1, j), optimalStrategyRec(a, i, j - 1));
}

int optimalStrategyDP(int* ar, int len) {
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    for(int gap = 0; gap < len; gap++) {
        for(int l = 0, h = gap; h < len; l++, h++) {
            int x = (l + 2 <= h) ? dp[l + 2][h] : 0;
            int y = ((l + 1) <= (h - 1)) ? dp[l + 1][h - 1] : 0;
            int z = (l <= h - 2) ? dp[l][h - 2] : 0;

            dp[l][h] = max(ar[l] + min(x, y), ar[h] + min(y, z));
        }
    } return dp[0][len - 1];
}

int optimalStrategyDPP(int* a , int n) {
	int dp[n][n];
	for (int i = n-1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j)
				dp[i][j] = 0;
			else if ((j - i + 1) % 2 == 0) // users turn
				dp[i][j] = max(a[i] + dp[i+1][j], a[j] + dp[i][j-1]);
			else // opponents turn
				dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
		}
	} return dp[0][n-1];
}

int main() {
    int ar[] = {3, 5, 6, 2, 3, 5};
    cout << optimalStrategyRec(ar, 0, 5);
    cout << optimalStrategyDP(ar, 6);
    cout << optimalStrategyDPP(ar, 6);
    return 0;
}