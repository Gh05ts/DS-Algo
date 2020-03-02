#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void subArraySum(int ar[], int len, int sum) {
    unordered_map<int, int> mp;
    int currSum = 0;
    for(int i = 0; i < len; i++) {
        currSum += ar[i];
        if(currSum == sum) {
            cout << "sum found between indexes" << 0 << "to" << i << endl;
            return;
        }
        if(mp.find(currSum - sum) != mp.end()) {
            cout << "Sum found between indexes" << mp[currSum - sum] + 1 << "to" << i << endl;
            return;
        }
        mp[currSum] = i;
    } cout << "No subarray with given sum exists";
}

int main() {
    int ar[] = {3, 34, 10, -2, 2, 18, -20};
    int len = sizeof(ar)/sizeof(ar[0]);
    int sum = 39;
    subArraySum(ar, len, sum);
    return 0;
}