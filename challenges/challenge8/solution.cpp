// Name: Robby Lawrence
// NetID: rlawren9
// Student ID: 000691931
// Description: Creates a Needleman-Wunsch table and outputs bottom right entry
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s_1, s_2;
    cin >> s_1;
    cin >> s_2;
    int m = s_1.size();
    int n = s_2.size();
    vector<vector<int> > vect(m + 1, vector<int>(n + 1, 0));

    // initialize first row
    for (int i = 0; i <= n; i++) {
        vect[0][i] = -i;
    }
    // initialize first column
    for (int i = 0; i <= m; i++) {
        vect[i][0] = -i;
    }
    // load vector
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int match = vect[i][j];
            if (s_1[i] == s_2[j]) {
                match += 1;
            }
            else {
                match -= 1;
            }
            int del = vect[i][j+1] - 1;
            int ins = vect[i+1][j] - 1;
            vect[i+1][j+1] = max({match, del, ins});
        }
    }
    // output the bottom right entry
    cout << vect[m][n] << endl;

    return 0;
}
