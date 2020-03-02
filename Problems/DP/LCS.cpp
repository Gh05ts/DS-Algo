#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lcsHelp(string s, string w, int slen, int wlen) {
    if(slen == 0 || wlen == 0) return 0;
    if(s[slen - 1] == w[wlen - 1]) return 1 + lcsHelp(s, w, slen - 1, wlen -1);
    else return max(lcsHelp(s, w, slen - 1, wlen), lcsHelp(s, w, slen, wlen - 1)); 
}

int lcs(string s, string w) {
    int slen = s.length();
    int wlen = w.length();
    return lcsHelp(s, w, slen, wlen);
}

int lcsDP(string s, string w) {
    int slen = s.length();
    int wlen = w.length();

    int dp[slen + 1][wlen + 1];

    for(int i = 0; i <= slen; i++) {
        for(int j = 0; j <= wlen; j++) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(s[i - 1] == w[j -1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    } return dp[slen][wlen];
}

int main() {

    string s = "AGGTAB";
    string w = "GXTXAYB";

    cout << lcs(s, w);
    cout << lcsDP(s, w);

    return 0;
}