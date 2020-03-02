#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& v) {
    if(v.size() <= 1) return;
     
    vector<int> left(v.begin(), v.begin() + v.size()/2);
    vector<int> right(v.begin() + v.size()/2, v.end());

    mergeSort(left);
    mergeSort(right);

    int l = 0; int r = 0;

    for(int i = 0; i < v.size(); i++) {
        if(r >= right.size() || (l < left.size() && left[l] <= right[r])) {
            v[i] = left[l++];
        } else v[i] = right[r++];
    }
}

int main() {
    vector<int> v = {323, 35, 2, 34, 55, 22345, -2, 33, 0, 0, 223};
    mergeSort(v);
    for(auto i = v.begin(); i != v.end(); i++) cout << *i << " ";
    return 0;
}