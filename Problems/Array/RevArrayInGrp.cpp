#include <iostream>
#include <algorithm>

using namespace std;

void revArrGrp(int ar[], int len, int k) {
    for(int i = 0; i < len; i += k) {
        int start = i;
        int end = min(len - 1, i + k - 1);
        while(start < end) {
            swap(ar[start++], ar[end--]);
        }
    }
}

int main() {
    int arr[] = {12, 23, 55, 77, 89, 212, 34};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    revArrGrp(arr, len, k);
    for(int s: arr) cout << s << " ";
    return 0;
}