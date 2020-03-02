#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int rainWater(vector<int>& v) {
    stack<int> st;
    int cur = 0, ans = 0;
    while(cur < v.size()) {
        while(!st.empty() && v[cur] > v[st.top()]) {
            int top = st.top(); st.pop();
            if(st.empty()) break;
            int dist = cur - st.top() - 1;
            int boundHeight = min(v[cur], v[st.top()]) - v[top];
            ans += dist * boundHeight;
        } st.push(cur++);
    } return ans;
}

int rainWater2(vector<int>& height) {
    int ans = 0, left = 0, right = height.size() - 1, temp = 0;
    while(left < right) {
        if(height[left] < height[right]) {
            temp = max(temp, height[left]);
            ans += temp - height[left++];
        } else {
            temp = max(temp, height[right]);
            ans += temp - height[right--]; 
        }
    } return ans;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; //{1, 2, 5, 1, 3, 4, 6, 9};
    cout << rainWater(height);
    cout << rainWater2(height);
    return 0;
}