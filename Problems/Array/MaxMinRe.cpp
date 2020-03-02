#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reMaxMin(vector<int> ar, int len) {
    int maxIdx = len - 1, minIdx = 0;
    int maxElem = ar[len - 1] + 1;

    for(int i = 0; i < len; i++) {
        if(i % 2 == 0) {
            ar[i] += (ar[maxIdx--] % maxElem) * maxElem;
           } else {
            ar[i] += (ar[minIdx++] % maxElem) * maxElem;
        }
    }

    for(int i = 0; i < len; i++) {
        ar[i] = ar[i] / maxElem;
        cout << ar[i];
    }
}

int main() {
    vector<int> ar = {1, 2, 3, 4, 5, 6, 7, 8};
    int len = ar.size();
    reMaxMin(ar, len);
    return 0;
}