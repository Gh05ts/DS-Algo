#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    vector<char> alphabets={'a' , 'c'};

    int freq[26];
    for(int i=0;i<26;i++){
        freq[i] = 0;
    }
    freq[0]=1;
    freq[2]=1;
    int total  = 2;
    int left =0;
    int count =0;
    for(int i=0;i<s.length();i++) {
        
        if (freq[s[i]-'a']>0){
            total--;
        }

        freq[s[i] - 'a']--;

        while(total<=0){
            int r = ++freq[s[left]-'a'];
            if (r > 0)
                total++;
            left++;
        }

        count += (i - left) + 1;
    }
    cout << count << "\n";
}