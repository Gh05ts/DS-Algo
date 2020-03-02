#include <iostream>
#include <vector>

using namespace std;

bool CanBeAbbreviated(string& a, string& b){
    int lenA(a.size()), lenB(b.size());
    vector<vector<bool>> canAbbre(lenA + 1, vector<bool>(lenB + 1, false));
    canAbbre[0][0] = true;

    for(int i = 1; i <= lenA && islower(a[i - 1]); ++i) canAbbre[i][0] = true ;

    for(int i = 1; i <= lenA; ++i) {
        for(int j = 1; j <= lenB; ++j) {
            if(islower(a[i - 1]) && canAbbre[i - 1][j])
            	canAbbre[i][j] = true;
            if(canAbbre[i - 1][j - 1] && (toupper(a[i - 1]) == b[j - 1] || a[i - 1] == b[j - 1]))
            	canAbbre[i][j] = true;
        }
    }
    return canAbbre[lenA][lenB];
}