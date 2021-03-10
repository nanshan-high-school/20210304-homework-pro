#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m;
    cin >> n;

    string str[2];
    for (int i = 0; i < 2; i++) {
        cin >> str[i];
    }

    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[m][n] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (str[0][i] == str[1][j]) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            } else {
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = max(dp[i][j - 1], 0);
                } else if (j == 0) {
                    dp[i][j] = max(dp[i - 1][j], 0);
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
    }

    cout << dp[m - 1][n - 1];
}
