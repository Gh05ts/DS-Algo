#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// have to add numer solution
string largestSum(vector<int> v) {
    vector<string> str;
    for(auto i: v) str.push_back(to_string(i));
    sort(str.begin(), str.end(), [](string& a, string& b) {return a + b > b + a;});
    string ret;
    if(str[0] == "0") return "0";
    for(auto i: str) ret += i;
    return ret;
}

int main() {
    vector<int> v = {32, 23, 33, 11, 3, 4, 837, 9, 31};
    cout << largestSum(v);
    return 0;
}