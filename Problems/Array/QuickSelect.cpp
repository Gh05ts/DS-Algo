#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;    

int partition(vector<int>& v, int left, int right) {
    int pivot = v[right];               // assigned random value
    int i = left - 1;                   // trailing tail, will rest at (pivot - 1)th place after pass
    for(int j = left; j < right; j++) { // right not included 
        if(v[j] <= pivot) {
            i++;                        // incremented and swapped
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[right]);           // pivot index, with tail + 1 (it's right place)
    return i + 1;
}

int partitionR(vector<int>& v, int left, int right) {
    srand(time(NULL));
    int random = left + floor(rand() % (right - left + 1));
    swap(v[random], v[right]);          // moved to end
    return partition(v, left, right);
}

int quickSelectSmall(vector<int>& v, int k, int l, int r) {
    if(l == r) return v[l];
    int pivot = partitionR(v, l, r);
    if(pivot == k) return v[k];
    else if(k < pivot) return quickSelectSmall(v, k , l, pivot - 1);
    else return quickSelectSmall(v, k, pivot + 1, r);               // shouldn't it be k - pivot???
}

int quickSelectSmall(vector<int>& v, int k) {
    return quickSelectSmall(v, k, 0, v.size() - 1);
}

int kthSmallest(vector<int>&v, int left, int right, int k) {
    for(;;) {
        if(left == right) return v[left];
        int pivotIndex = partitionR(v, left, right);
        
        if(k == pivotIndex) return v[k];
        else if (k < pivotIndex) right = pivotIndex - 1;
        else left = pivotIndex + 1;
    }
}

int main() {
    vector<int> v = {23, 33, 5, -3, 0, 0, 53, 52};
    for(int i = 0; i < v.size(); i++) {
        cout << quickSelectSmall(v, i) << endl;
        cout << kthSmallest(v, 0, v.size() - 1, i) << endl;
    }
    return 0;
}