#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector<int> merge(vector<int>& left, vector<int>& right) {
//     vector<int> res(left.size() + right.size());
//     int l = 0, r = 0;
//     for(int i = 0; i < res.size(); i++) {
//         if(r >= right.size() || (l < left.size() && left[l] <= right[r])) res[i] = left[l++];
//         else res[i] = right[r++];
//     } return res;
// }

void mergeNO(vector<int>& a, vector<int>& b) {
    const int cap1 = a.size();
    const int cap2 = b.size();

    int pos1 = 0;
    int pos2 = 0;

    while (pos1 + pos2 < cap1 && pos2 < cap2) {
        if (a[pos1] <= b[pos2]) {
            pos1++;
        } else {
            pos2++;
        }
    }

    const int insertionStart = cap1 - pos2;

    for (int i = 0; i < pos2; i++) {
        swap(a[pos1 + i], b[i]);
    }    
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
}

int main() {
    vector<int> a = {1, 5, 9, 10, 15, 20};//{10};
    vector<int> b = {2, 3, 8, 13};//{2, 3};
    // vector<int> res = merge(a, b);
    mergeNO(a, b);
    for(auto i = a.begin(); i != a.end(); i++) cout << *i << " ";
    for(auto i = b.begin(); i != b.end(); i++) cout << *i << " ";
    return 0;
}