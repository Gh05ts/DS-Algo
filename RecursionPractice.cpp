#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void collapseSequencesHelper(string&, char, string&, int);

void rec(int n) {
    if(!(n < 0)) {
        cout << n << endl;
        rec(n-1);
        cout << n << endl;
    }
}

int toh(int n, char src, char des, char aux, int &count) {
    if(n == 1) { 
        cout << "Move disk " << n << " from rod " << src << " to rod " << des << endl;
        ++count;
    } else {
        toh(n-1, src, aux, des, count);
        cout << "Move disk " << n << " from rod " << src << " to rod " << des << endl;
        ++count; 
        toh(n-1, aux, des, src, count);
    } return count;
}

int nHanoi(int size) {
    int i = 0;
    return toh(size, 'A', 'B', 'C', i);

}

void recursivePermute(string prefix, string rest) {
    if(rest == "") {
        cout << prefix << endl;
    } else {
        for(int i = 0; i < rest.length(); i++) {
            string newPrefix = prefix + rest[i];
            string newRest = rest.substr(0, i) + rest.substr(i+1);
            recursivePermute(newPrefix, newRest);
        }
    }
}

void listPermutate(string str) {
    recursivePermute("", str);
}

void recPerrmute(string prefix, string rest, set<string>& printed) {
    if(rest == "") {
        // if(printed.find(prefix) == printed.end()) {
            cout << prefix << endl;
            // printed.insert(prefix);
        // }
    } else {
        for(int i = 0; i < rest.length(); i++) {
            char first = rest[i];
            prefix += first;
            rest.erase(i, 1);

            recPerrmute(prefix, rest, printed);

            rest.insert(i, 1, first);
            prefix.erase(prefix.length() - 1, 1);
        }
    }
}

string collapseSequences(string s, char c) {
    string temp;
    int i = 0;
    collapseSequencesHelper(s, c, temp, i);
    return temp;
}

void collapseSequencesHelper(string& s, char c, string& temp, int i) {
    if(i < s.length()) {
        if(temp.empty() || s[i] != c || temp[temp.length() - 1] != s[i]) {
            temp.push_back(s[i]);
        }
        collapseSequencesHelper(s, c, temp, i + 1);
    }
}

void removeDuplicatesHelper(string& s, string& temp, int i) {
    if(i < s.length()) {
        if(temp.empty() || temp[temp.length() - 1] != s[i]) {
            temp.push_back(s[i]);
        } removeDuplicatesHelper(s, temp, i+1);
    }
}

string removeDuplicates(string s) {
    string temp;
    int i = 0;
    removeDuplicatesHelper(s, temp, i);
    return temp;
}

long long int combinMemo(int n, int k, int memo[], int kmax)  {
    long comVal = 0;
    if (k == 0) return 1;
    if (n == k) return 1;
    if(n < k || (n <= 0)) return 0;
    if(memo[n*(kmax) + k] == 0) {
        return memo[n*(kmax) + k] = (combinMemo(n - 1, k - 1, memo, kmax)) + combinMemo(n - 1, k, memo, kmax);          //+ combinMemo(n - 1, k, memo));
    } else {
        return memo[n*(kmax) + k];
    }
}

long long int combinMemoWrap(int n, int k) {
    int memo[(n + 1) * (k + 1)];
    for(int i = 0; i < (n + 1) * (k + 1); i++) {
            memo[i] = 0;
    }
    int kmax = k;
    return combinMemo(n, k, memo, kmax);
}

long long int combin(int n, int k) {
    if (k == 0) return 1;
    if (n == k) return 1;
    if(n < k || (n <= 0)) return 0;
    else {
        return (n/k)*combin(n - 1, k - 1);  // + combin(n - 1, k);
    } 
}

// stack<int> revStack(stack<int> start) {
//     stack<int> temp;
//     int t = start.top();
//     if(start.empty()) {
//         return temp;
//     } else {
//         start.pop();
//         temp.push(t);
//         revStack(start);
//     }
//     return temp;
// }




int main() {
    int i = 0;
    // rec(70);
    
    // cout << nHanoi(4);
    // listPermutate("MARTY");
    // set<string> printed;
    // recPerrmute("", "carda", printed);
    //zt2 cout << removeDuplicates("axcccadscccsdddfffdxcc");
    cout << combinMemoWrap(7, 4);
    // stack<int> something;
    // something.push(3);
    // something.push(2);
    // something.push(1);
    // something = revStack(something);
    // while(!something.empty()) {
    //     int s = something.top();
    //     something.pop();
    //     cout << s << endl;
    // }
    return 0;
}