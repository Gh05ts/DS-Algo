#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leaderBoard(vector<int> scores, vector<int> alice) {
    auto it = unique(scores.begin(), scores.end());
    scores.erase(it, scores.end());
    vector<int> res(alice.size());
    int si = scores.size() - 1, ai = 0;
    for(int s: alice) {
        while(si >= 0) {
            if(s >= scores[si]) si--;
            else {
                res[ai++] = si + 2; break;
            }
        }
        if(si < 0) res[ai++] = 1; 
    } return res;
}

int main() {
    vector<int> scores = {210, 209, 105, 85, 39, 25};
    vector<int> alice = {6 ,38, 43, 87, 152, 155, 209, 289};
    vector<int> res = leaderBoard(scores, alice);
    for(auto i = res.begin(); i != res.end(); i++) cout << *i << " ";
    return 0;
}