#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int missingNumber(int ar[], int len) {
    int a = ar[0];
    for(int i = 1; i < len; i++) {
        if(ar[i] - 1 == a) a = ar[i];
        else {
            a = ar[i] - 1;
            break;
        }
    } return a;
}

int main() {
    int ar[] = {1, 2, 3, 4, 6, 7, 8};
    int len = sizeof(ar)/sizeof(ar[0]);
    cout << missingNumber(ar, len);
    return 0;
}