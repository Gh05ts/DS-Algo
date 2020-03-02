#include <iostream>

using namespace std;

long long ans = 0;

void mergei(int a[],int i,int j, long long& ans) {
    int ni = ((i+j)/2) + 1, nj = j + 1;
    int s = i;
    int* arr = new int [j - i + 1];
    j = ni;
    int k = 0;

    while(i < ni && j < nj) {
        if(a[i] <= a[j]){
            arr[k] = a[i++];
        } else {
            arr[k] = a[j++];
            ans += (ni - i);
        } k++;
    }

    for(;i < ni; i++, k++) arr[k] = a[i];
    for(; j < nj; j++, k++) arr[k] = a[j];
    for(k = 0; s < nj; s++, k++) a[s] = arr[k];
    delete [] arr;
}

void m_sort(int a[],int i,int j) {
    if(i < j) {
        m_sort(a, i, (i+j)/2);
        m_sort(a, ((i+j)/2) + 1, j);
        mergei(a, i, j, ans);
    } 
}

int main() {
    int ar[] = {2, 1, 3, 1, 2};
    int len = sizeof(ar)/sizeof(ar[0]);
    m_sort(ar, 0, len - 1);
    cout << ans;
    return 0;
}