#include <bits/stdc++.h> 
using namespace std; 

int CountSpecialPalindrome(string s, int n) {

    int count = 0;
    vector<pair<char, int>> frequencies; // a tuple to store frequencies of same contiguous characters
    int i, j;

    //storing the frequencies of same contiguous characters
    for ( i = 0; i < n; i++) {
        for( j = i+1; j < n; j++) {
            if (s[j] == s[i])
                continue;
            else
                break;
        }
        frequencies.push_back(make_pair(s[i],j-i));
        i = j-1;
    }
    
    //for counting even special palindromes of aaaaa type
    for (i=0; i < frequencies.size(); i++)
        count += (frequencies[i].second + 1) * frequencies[i].second / 2;

    //for counting special palindromes of aabaa type
    for (i=1; i < frequencies.size()-1; i++) {
        if ( frequencies[i].second == 1 && frequencies[i-1].first == frequencies[i+1].first)
            count += min(frequencies[i-1].second, frequencies[i+1].second);
    }
    return count - n; //subtract size 1 substrings
}


int main() { 
    string str = "AyyoooooAyyyooooo"; // answer should be 3 i.e. bcb, bab, aba
    cout << CountSpecialPalindrome(str, str.length()) << endl; 
    return 0; 
} 