#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sublists(vector<string>& v);
void sublistsHelper(vector<string>& v, vector<string>& chosen);

int main() {

    vector<string> list = {"Bob", "Jane", "Kyle", "Derrick"};
    sublists(list);
    return 0;
}

void sublists(vector<string>& v) {
    vector<string> chosen;
    sublistsHelper(v, chosen);
}

void sublistsHelper(vector<string>& v, vector<string>& chosen) {
    if(v.empty()) {
        cout << "{ ";
        for(string s : chosen) {
            cout << s << " ";
        } cout << "}" << endl;
    } else {
        string first = v[0];
        v.erase(v.begin());

        chosen.push_back(first);
        sublistsHelper(v, chosen);

        chosen.pop_back();
                                                                // chosen.push_back(first);  #2
        sublistsHelper(v, chosen);

                                                                // chosen.pop_back(); #2
        // v.insert(v.begin(), first);
    }
}
