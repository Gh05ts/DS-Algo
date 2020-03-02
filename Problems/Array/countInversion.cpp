#include <iostream>
#include <vector>

using namespace std;

long mergeSort(vector<int>& v) {
    if(v.size() <= 1) return 0;

    vector<int> left(v.begin(), v.begin() + v.size()/2);
    vector<int> right(v.begin() + v.size()/2, v.end());

    long inv = mergeSort(left) + mergeSort(right);

    int l = 0, r = 0;

    for(int i = 0; i < v.size(); i++) {
        if(r >= right.size() || (l < left.size() && left[l] <= right[r])) {
            v[i] = left[l++];
            inv += r;
        } else v[i] = right[r++];
    }

    return inv;
    // return merge(v, left, right, inv);
}

int main() {
    vector<int> v = {2, 1, 3, 1, 2};    //{1, 1, 1, 2, 2}; //{2, 1, 3, 1, 2};//{1, 1, 1, 2, 2};//{22, 18, 12, -4, 58, 7, 31, 42}; //{12, 34, 11, 35, 66, 32, 98};//{22, 18, 12, -4, 58, 7, 31, 42};//
    printf("No. of Inversions %d", mergeSort(v));
    // for(auto i = v.begin(); i != v.end(); i++) cout << *i << " ";
    return 0;
}