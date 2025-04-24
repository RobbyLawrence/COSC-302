// Name: Robby Lawrence
// NetID: rlawren9
// Student ID: 000691931
// Description: Creates a Needleman-Wunsch table and outputs bottom right entry
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    string s_1, s_2;
    cin >> s_1;
    cin >> s_2;
    int m = s_1.size();
    int n = s_2.size();
    vector<vector<int> > vect(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n+1; i++) { // put negatives in first row and column
        vect[0][i] = -i;
    }
    for (int i = 0; i < m+1; i++) {
        vect[i][0] = -i;
    }
    // load vector
    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
            int match = vect[i-1][j-1];
            if (s_1[i] == s_2[j]) {
                match += 1;
            }
            else {
                match -= 1;
            }
            int top = vect[i-1][j] - 1;
            int left = vect[i][j-1] - 1;
            vect[i][j] = max({match, left, top});
        }
    }

    for (int i = 0;i<m+1;i++) {
        for (int j = 0;j<n+1;j++) {
            cout << setw(2) << vect[i][j] << " ";
        }
        cout << endl;
    }

    // output the bottom right entry
    cout << vect[m][n] << endl;

    return 0;
}
