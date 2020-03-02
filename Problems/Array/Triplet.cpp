#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int countTriplet(int ar[], int len, int sum) {
    sort(ar, ar + len);
    int ans = 0;
    for(int i = 0; i < len - 2; i++) {
        int j = i + 1; int k = len - 1;
        while(j < k) {
            if(ar[i] + ar[j] + ar[k] >= sum) k--;
            else {
                ans += (k - j);
                j++;
            }
        }
    } return ans;
}

int main() {
    int ar[] = {4, 5, 2, 46, 2, 7, 6};
    int len = sizeof(ar)/sizeof(ar[0]);
    cout << countTriplet(ar, len, 15);
    return 0;
}