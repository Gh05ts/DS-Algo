/*
 * CS106B, Julie Zelenski
 *
 * This program contains lecture examples that demonstrate use of recursion to
 * exhaustively explore a search space.
 */

#include <iostream>    // for cout, endl
#include <string>      // for string class

using namespace std;

// function prototype declarations
void sublists(vector<string>& v);
void sublistsHelper(vector<string>, vector<string>);

int main() {
    vector<string> names {"Jane", "Bob", "Matt", "Sara"};
    cout << "sublists of " << names << ":" << endl << endl;
    sublists(names);
    return 0;
}

/*
 * Prints all subsets of the given vector.
 * This is somewhat similar to printing permutations, except that a permutation
 * includes all elements of the vector, and what differs is their order.
 * For subsets, the order is irrelevant; what matters is which elements are
 * included and which are excluded from the subset.
 * So those decisions (include/exclude?) represent our "choices".
 */
void sublists(vector<string>& v) {
    // TODO
}

void sublistsHelper(vector<string>& v, vector<string>& chosen) {
    if(v.empty()) {
        // base case
    } else {
        // recursive case
        // for all values
        string s = v[0];
        v.remove()
        for(int i = 0; i < (int)v.size(); i++) {

        }
    }
}