#include <iostream>
#include <algorithm>

using namespace std;

int minPlat(int a[], int b[], int len) {
    sort(a, a + len);
    sort(b, b + len);

    int l = 0, r = 0;
    int maxPlat = 0;
    while(l < len) {
        if(a[l] <= b[r]) l++;
        else r++;
        maxPlat = max(maxPlat, l - r);
    } return maxPlat;
}

int main() {
    int a[] = {900, 940, 950, 1100, 1500, 1800};
    int b[] = {2000, 2000, 1120, 2030, 1900, 2000};
    int len = sizeof(a)/sizeof(a[0]);
    cout << minPlat(a, b, len);
    return 0;
}