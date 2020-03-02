#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

int partition(vector<int>& v, int left, int right) {
    int pivot = v[right];
    int i = left - 1;
    for(int j = left; j < right; j++) {
        if(v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[right]); // pivot index, with tail + 1 (it's right place)
    return i + 1;
}

int partitionR(vector<int>& v, int left, int right) {
    srand(time(NULL));
    int random = left + floor(rand() % (right - left + 1));
    swap(v[random], v[right]);
    return partition(v, left, right);
}

void quickSort(vector<int>& v, int left, int right) {
    if(left < right) {
        int p = partitionR(v, left, right);
        quickSort(v, left, p - 1);
        quickSort(v, p + 1, right);
    }
}

void quickSort(vector<int>& v) {
    quickSort(v, 0, v.size() - 1);
}

int main() {
    vector<int> v = {3, 2, 34, 22, -2, 0, 0, 34, 999, 1}; 
    quickSort(v);
    for(int i: v) cout << i << " ";
    return 0;
}