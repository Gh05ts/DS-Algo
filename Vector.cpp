#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countInRange(vector<int>& v, int min, int max) {
    int count = 0;
    for (int num: v)
    {
        if (num >= min && num <= max)
        count++;
    }
    return count;   
}

void removeAll(vector<string>& v, string s) {
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == "b") {
            v.erase(v.begin()+i);
        }
    }

}

int main() {

    vector<int> v;
    vector<string> v2;
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(3);
    // for (size_t i = 0; i < 2; i++)
    // {
    //     v.push_back(i);
    // }
    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i)<<endl;
    // }
    // v.erase(v.begin()+4);
    //     for (size_t i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i)<<endl;
    // }
    // v[2] = 9;
    //         for (size_t i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i)<<endl;
    // }

    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     /* code */
    //     v.erase(v.begin()+i);
    // }

//////// countInRange
    v = {28, 1, 17, 4, 41, 9, 59, 8, 31, 30, 25};
    v2 = {"a", "b", "c", "b", "b", "a", "b"};
    int count = countInRange(v, 10, 30);
    cout << "the count is " << count << endl;
    removeAll(v2, "b");
    for(string s: v2) {
        cout<<s<<endl;
    }
    
    return 0;
}