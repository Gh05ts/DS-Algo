#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int editDistanceHelp(string s, string w, int slen, int wlen) {
    if(slen == 0) return wlen;
    if(wlen == 0) return slen;
    if(s[slen - 1] == w[wlen - 1]) return editDistanceHelp(s, w, slen - 1, wlen - 1);
    return 1 + min({editDistanceHelp(s, w, slen - 1, wlen), editDistanceHelp(s, w, slen, wlen - 1), editDistanceHelp(s, w, slen - 1, wlen - 1)});
}

int editDistance(string s, string w) {
    int slen = s.length();
    int wlen = w.length();
    return editDistanceHelp(s, w, slen, wlen);
}

int editDistanceDP(string s, string w) {
    int slen = s.length();
    int wlen = w.length();
    
    int dp[slen + 1][wlen + 1];
    for(int i = 0; i <= slen; i++) {
        for(int j = 0; j <= wlen; j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s[i - 1] == w[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i -1][j - 1]});
        }
    } return dp[slen][wlen];
}

int main() {
    string s1 = "sunday";
    string s2 = "saturday";
    
    cout << editDistance(s1, s2);
    cout << editDistanceDP(s1, s2);

    return 0;
}