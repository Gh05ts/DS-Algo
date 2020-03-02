#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <list>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <stack>

using namespace std;

// vector<int> maxSubarray(vector<int> arr) {
//     bool flag = true;
//     int absMax = -80000, maxSub = -80000, curMax = absMax;
//     for(int i = 0; i < arr.size(); i++) {
//         curMax = max(curMax + arr[i], arr[i]);
//         if(curMax > absMax) absMax = curMax;
//         if(arr[i] > 0) {
//             if(flag) {maxSub = 0; flag = false;}
//             maxSub += arr[i];
//         }
//     }
//     if(flag) maxSub = absMax;
//     vector<int> v = {absMax, maxSub};
//     return v;
// }

    // int peakHelper(vector<int>& v, int left, int right) {
    //     int mid = left + (right - left)/2;
    //     if((v[mid - 1] < v[mid] || mid == 0) && (v[mid] > v[mid + 1] || mid == v.size() - 1)) return mid;
    //     else if(v[mid - 1] > v[mid]) return peakHelper(v, left, mid - 1);
    //     else return peakHelper(v, mid + 1, right);
    // }

    // int findPeakElement(vector<int>& nums) {
    //     return peakHelper(nums, 0, nums.size() - 1);

    // }
// vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
//     vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
//     for(int i = 1; i <= a.size() - 1; i++) {
//         for(int j = 1; j <= b.size() - 1; j++) {
//             if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
//             else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }

//     int index = dp[a.size()][b.size()];
//     vector<int> result(index + 1, 1);
//     int first = a.size(), second = b.size();
//     while(first > 0 && second > 0) {
//         if(a[first - 1] == b[second - 1]) {
//             result[index - 1] = a[first-1];
//             index--; first--; second--;
//         }
//         else if(dp[first - 1][second] > dp[first][second - 1]) first--;
//         else second--;

//     }
//     return result;
// }
// vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
//     int len = a.size();
//     k %= len;
//     for(int i = 0; i < queries.size(); i++) {
//         // queries[i] = a[(len - k + queries[i]) % len];
//         int a = (len - k + queries[i]) % len;
//         int b = len + ((queries[i] - k) % len);
//         int c = 500;
//     } return queries;
// }
// int dig(int n) {
//     int temp = n;
//     int count = 0;
//     while(temp) {
//         int last = n %10;
//         temp /= 10;
//         if(last == 0) continue;
//         if(n % last == 0) count++;
//     } return count;
// }

// vector<vector<int>> Graph(vector<vector<int>>& edges, int n) {
//     vector<vector<int>> ans;
//     ans.resize(n);
//     for(auto i: edges) {
//         ans[i[0]].push_back(i[1]);
//         ans[i[1]].push_back(i[0]);
//     } return ans;
// }

// vector<int> bfs(int n, int m, vector<vector<int>>& edges, int s) { // no. of vertex, no. of edges, edges, start
//     vector<vector<int>> adjList;
//     adjList = Graph(edges, n + 1);
//     vector<int> ans(n + 1, -1);
//     vector<bool> visited(n + 1);
//     queue<int> q;
//     visited[s] = true;
//     q.push(s);
//     ans[s] = 0;
//     while(!q.empty()) {
//         int temp = q.front(); q.pop();
//         for(int j: adjList[temp]) {
//             if(!visited[j]) {
//                 ans[j] = 6 + ans[temp];
//                 visited[j] = true;
//                 q.push(j);
//             }
//         }
//     }
//     ans.erase(ans.begin() + s - 1);
//     ans.erase(ans.begin());
//     return ans;
// }
//     vector<int> len(100, 0);
// int bfs(vector<vector<int>>& board) {
//     queue<int> q;
//     vector<bool> visit(101, false);

//     visit[1] = true;
//     q.push(1);
//     while(!q.empty()) {
//         int temp = q.front(); q.pop();
//         if(temp > 100 || temp < 1) continue;
//         for(auto i: board[temp]) {
//             if(!visit[i]) {
//                 if(i == 100) return (len[temp] + 1);
//                 visit[i] = true;
//                 q.push(i);
//                 len[i] = len[temp] + 1;
//             }
//         }
//     } return -1;
// }

// int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
//     vector<vector<int>> board(101);
//     vector<int> mpl(101, 0);
//     vector<int> mps(101, 0);
//     for(auto i: ladders) mpl[i[0]] = i[1];
//     for(auto i: snakes) mps[i[0]] = i[1];
//     for(int i = 1; i <= 100; i++) {
//         for(int j = 1; j <= 6; j++) {
//             if(mpl[i] || mps[i]) continue;
//             else if((i + j) <= 100) {
//                 if(mpl[i + j]) board[i].push_back(mpl[i + j]);
//                 else if(mps[i + j]) board[i].push_back(mps[i + j]);
//                 else board[i].push_back((i + j));
//             }
//         }
//     } 
//     // queue<int> q;
//     // vector<bool> visit(101, false);
//     // vector<int> len(100, 0);
//     // visit[1] = true;
//     // q.push(1);
//     // while(!q.empty()) {
//     //     int temp = q.front(); q.pop();
//     //     if(temp > 100 || temp < 1) continue;
//     //     for(auto i: board[temp]) {
//     //         if(!visit[i]) {
//     //             if(i == 100) return (len[temp] + 1);
//     //             visit[i] = true;
//     //             q.push(i);
//     //             len[i] = len[temp] + 1;
//     //         }
//     //     }
//     // } return -1;
//     return bfs(board);
// }

// vector<int> largestPermutation(int k, vector<int> arr) {
//     vector<int> map(arr.size() + 1);
//     for(int i = 0; i < arr.size(); i++) map[arr[i]] = i;
//     vector<int> cop = arr;
//     sort(cop.rbegin(), cop.rend());
//     int i = 0;
//     while(i < arr.size() &&  k) {
//         if(cop[i] > arr[i]) { 
//             auto temp = arr[i]; 
//             swap(arr[i], arr[map[cop[i]]]);
//             map[temp] = map[cop[i]];
//             k--;
//             }
//         i++;
//     }
//     return arr;
// }

// vector<int> largestPermutation1(int k, vector<int> arr) {
//     vector<int> map(arr.size() + 1);
//     for(int i = 0; i < arr.size(); i++) map[arr[i]] = i;
//     vector<int> cop(arr.size());
//     for(int i = 0; i < arr.size(); i++) arr[i] = arr.size() - i;
//     int i = 0;
//     while(i < arr.size() &&  k) {
//         if(cop[i] > arr[i]) { 
//             auto temp = arr[i]; 
//             swap(arr[i], arr[map[cop[i]]]);
//             map[temp] = map[cop[i]];
//             k--;
//             }
//         i++;
//     }
//     return arr;
// }

    // void rec(vector<int>& chosen, vector<int>& nums, vector<vector<int>>& ans) {
    //     if(nums.size() == 0) ans.emplace_back(chosen);
    //     else {
    //         int first = nums[0];

    //         nums.erase(nums.begin());

    //         chosen.emplace_back(first);
    //         rec(chosen, nums, ans);

    //         chosen.pop_back();
    //         rec(chosen, nums, ans);

    //         nums.insert(nums.begin(), first);
    //     }
    // }
    
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     vector<int> chosen;
    //     vector<vector<int>> ans;
    //     rec(chosen, nums, ans);
    //     return ans;
    // }

    // int lengthOfLongestSubstring(string s) {
    //     vector<int> map(3);
    //     int start(0), end(0), count(0);
    //     while(start < s.size() && end < s.size()) {
    //         if(map[s[end] - 'a'] == 0) {
    //             count = max(count, end - start + 1);
    //             map[s[end++] - 'a']++;
    //         } else {
    //             while(start != end) {
    //                 map[start++]--;
    //             }
    //         }
    //     }
    //     return count;
    // }

    // int minJumps(vector<int>& arr) {
    //     unordered_map<int, vector<int>> indices;
    //     for(int i = 0; i < arr.size(); i++) indices[arr[i]].emplace_back(i);
        
    //     queue<int> q;
    //     q.push(0);
    //     vector<int> dist(arr.size());
    //     dist[0] = 0;

    //     while(!q.empty()) {
    //         int temp = q.front(); q.pop();
    //         if(temp == arr.size() - 1) return dist[temp];   
    //         vector<int>& next = indices[arr[temp]];
    //         next.emplace_back(temp - 1), next.emplace_back(temp + 1);
    //         for(const auto &i: next) {
    //             if(i >= 0 && i < arr.size() && !dist[i]) {
    //                 dist[i] = 1 + dist[temp];
    //                 q.push(i);
    //             }
    //         }
    //         next.clear();
    //     }
    //     return -1;
    // }

    // void countInversion(vector<int>& ans, vector<pair<int, int>>& valInd) {
    //     if(valInd.size() <= 1) return;
        
    //     vector<pair<int, int>> left(valInd.begin(), valInd.begin() + valInd.size()/2);
    //     vector<pair<int, int>> right(valInd.begin() + valInd.size()/2, valInd.end());
        
    //     countInversion(ans, left);
    //     countInversion(ans, right);
        
    //     int l = 0, r = 0;
        
    //     for(int i = 0; i < valInd.size(); i++) {
    //         if(r >= right.size() || (l < left.size() && left[l].second <= right[r].second)) {
    //             valInd[i] = left[l++];
    //             ans[valInd[i].second] += r;
    //         } else {
    //             valInd[i] = right[r++];
    //         }
    //     }
    // }
    
    // vector<int> countSmaller(vector<int>& nums) {
    //     if(nums.size() < 1) return {};
    //     vector<pair<int, int>> valInd(nums.size());
    //     for(int i = 0; i < nums.size();i++) valInd[i] = {nums[i], i};
    //     vector<int> ans(nums.size());
    //     countInversion(ans, valInd);
    //     return ans;
    // }

// class LRUCache {
// private:
//     int cap;
//     unordered_map<int, pair<int, list<int>::iterator>> map;
//     list<int> LRU;
// public:
//     void maintain(unordered_map<int, pair<int, list<int>::iterator>>::iterator &it) {
//         LRU.erase(it->second.second);
//         LRU.push_front(it->first);
//         it->second.second = LRU.begin();
//     }
    
//     LRUCache(int capacity) {
//         cap = capacity;
//     }
    
//     int get(int key) {
//         auto it = map.find(key);
//         if(it == map.end()) return -1;
//         else {
//             maintain(it);
//             return it->second.first;
//         }
//     }
    
//     void put(int key, int value) {
//         // we keep our population under control like china pre 2015
//         if(map.size() == cap) {
//             map.erase(LRU.back());
//             LRU.pop_back();
//         }
//         // list can't handle repeats, gotta do the work.
//         auto it = map.find(key);
//         if(it == map.end()) {
//             LRU.push_front(key);
//             map[key] = {value, LRU.begin()};
//         } else {
//             maintain(it);
//             map[key] = {value, LRU.begin()};
//         }
//     }
// };

// int change(int amount, vector<int>& coins) {
//     vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1));
//     for(int i = 0; i <= coins.size(); i++) dp.at(i).at(0) = 1;
//     for(int i = 1; i <= coins.size(); i++) {
//         for(int j = 1; j <= amount; j++) {
//             if(j - coins.at(i - 1) >= 0) dp.at(i).at(j) = dp.at(i - 2).at(j) + dp.at(i - 1).at(j - coins.at(i - 1));
//             else dp.at(i - 1).at(j) = dp.at(i - 1).at(j);
//         }
//     }
//     return dp.at(coins.size()).at(amount);
// }

//     int myAtoi(string str) {
//         int i(0), j(str.size() - 1);
//         int ans(0);
//         while(str[i] == ' ') i++;
//         if(str[i] == '-' || str[i] == '+') i++;
//         bool isNeg = false;
//         if(i - 1 >= 0 && str[i - 1] == '-') isNeg = true;
//         while(i <= j) {
//             int val = str[i] - '0';
//             if(!isdigit(str[i])) break;
//             if(ans > INT_MAX/10) return isNeg ? INT_MIN : INT_MAX;
//             ans *= 10;
//             if(ans == INT_MAX/10 && val > INT_MAX % 10) return isNeg ? INT_MIN : INT_MAX;
//             ans += (str[i++] - '0');
//         }
//         return isNeg ? -ans : ans;
//     }

// string simplifyPath(string path) {
// stack<string> path_parts;
// stringstream sstream { path };

// string buffer;
// buffer.reserve(path.size());  // reserve max-space to avoid allocations

// split the string using '/' as delimiter
// while (getline(sstream, buffer, '/')) {
//     if (buffer.empty() || buffer == ".") {
//         continue;
//     }
//     if (buffer == "..") {
//         if (!path_parts.empty()) {
//             path_parts.pop();
//         }
//     } else {
//         path_parts.push(buffer);
//     }
// }

// // clear the buffer, use it to rebuild the path
// buffer.clear();

// while (!path_parts.empty()) {
//     auto part = path_parts.top();
//     path_parts.pop();
//     buffer.insert(0, "/" + part);
// }

// return buffer.empty() ? "/" : buffer;
// }

// string simplifyPath(string path) {
//     stack<string> st;
//     stringstream ss{path};
    
//     string buf;
    
//     while(getline(ss, buf, '/')) {
//         if(buf.empty() || buf == ".") continue;
//         if(buf == "..") {
//             if(!st.empty()) st.pop();
//         }
//         else st.push(buf);   
//     }
//     buf.clear();
    
//     while(!st.empty()) {
//         string temp = st.top(); st.pop();
//         buf += temp;
//     }
//     return buf;
// }
vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    int countMine(vector<vector<char>> &board, int x, int y) {
        int count(0);
        for(int i = x-1; i <= x+1; i++) {
            for(int j = y-1; j <= y+1; j++) {
                if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'M') count++;
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>> &board, int x, int y) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'E') return;
        int mines = countMine(board, x, y);
        if(mines > 0) {
            board[x][y] = '0' + mines;
        } else {
            board[x][y] = 'B';
            for(const auto &d: dirs) {
                dfs(board, x + d[0], y + d[1]);
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;   
        }
        dfs(board, click[0], click[1]);
        return board;
    }

int main() {
    // vector<int> v = {1, 2, 3};// {1, 2, 4, 5, 6, 7, 4};//{-2, -3, -1, -4, -6};
    // vector<int> x = {0, 1, 2}; //{1, 6, 4, 4, 6, 3};
    // vector<int> s = maxSubarray(v);
    // for(auto i: s) cout << i << endl;
    // cout << findPeakElement(v);
    // vector<int> ans = longestCommonSubsequence(v, x);
    // for(int a: ans) cout << a;
    // vector<int> ans = circularArrayRotation(v, 2, x);
    // for(int a: ans) cout << a;
    // cout << dig(1012);
    // vector<vector<int>> edges = { {1, 2}, {1, 3}, {3, 4} };//{{1, 2}, {1, 3} };//{{2, 3}};//{{1, 2}, {1, 3} };
    // vector<int> som = bfs(5, 3, edges, 1);
    // vector<vector<int>> ladder = { {32, 62}, {42, 68}, {12, 98} };
    // vector<vector<int>> snake = { {95, 13}, {97, 25}, {93, 37}, {79, 27}, {75, 19}, {49, 47}, {67, 17} };
    // cout << quickestWayUp(ladder, snake);
    // for(int i: len) cout << i << " ";
    // for(int i = 0; i < 10; i++) cout << i << " ";
    // cout << endl;
    // for(int i = 0; i < 10; ++i) cout << i << " ";
    // vector<int> inp = {4, 2, 3, 5, 1};
    // largestPermutation(1, inp); 
    // largestPermutation1(1, inp); 
    // vector<int> nums = {1, 3, 2, 4};
    // vector<vector<int>> ans = subsetsWithDup(nums);
    // lengthOfLongestSubstring("abcabcbb");
    // vector<int> arr{100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    // cout << minJumps(arr);
    // vector<int> di{0, 0};
    // di[0] = 0;
    // if(!di[0]) cout << "YES";
    // vector<int> nums{5, 2, 6, 1};
    // countSmaller(nums);
    // LRUCache *c = new LRUCache(2);
    // int p1 = c->get(2);
    // c->put(2, 6);
    // int p2 = c->get(1);
    // c->put(1, 1);
    // c->put(1, 5);
    // int p3 = c->get(1);
    // int p4 = c->get(2);
    // vector<int> v{1, 2, 5};
    // cout << change(5, v);
    // cout << myAtoi("-2147483649");
    // cout << simplifyPath("/a/../../b/../c//.//");
    // cout << simplifyPath("/home/");
    vector<vector<char>> board { {'E','E','E','E','E'}, 
                                 {'E','E','M','E','E'}, 
                                 {'E','E','E','E','E'}, 
                                 {'E','E','E','E','E'} };
    vector<int> click{3, 0};
    board = updateBoard(board, click);
    return 0;
}

// bool check(TreeNode *a,TreeNode *b){
//     if(!a && !b) return true;
//     if(!a || !b) return false;
//     if(a->key == b->key && check(a->left, b->right) && check(a->right, b->left)) return true;
//     return false;
// }
