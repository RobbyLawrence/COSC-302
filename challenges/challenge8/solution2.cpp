#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize first row
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = -j;
    }

    // Initialize first column
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = -i;
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int match = dp[i-1][j-1] + (s1[i-1] == s2[j-1] ? 1 : -1);
            int del = dp[i-1][j] - 1;
            int ins = dp[i][j-1] - 1;
            dp[i][j] = max({match, del, ins});
        }
    }
    for (vector<int> vect : dp) {
        for (int entry : vect) {
            cout << setw(2) << entry << " ";
        }
        cout << endl;
    }

    cout << dp[m][n] << endl;

    return 0;
}
