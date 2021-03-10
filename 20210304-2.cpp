#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    string str1, str2, str3;
    cin >> str1;
    cin >> str2;
    cin >> str3;

    int dp[a][b][c];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                dp[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                if ((str1[i] == str2[j]) && (str1[i] == str3[k])) {
                    if ((i == 0 || j == 0) || k == 0) {
                        dp[i][j][k] = 1;
                    } else {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    }
                } else {
                    if ((i == 0 && j == 0) && k == 0) {
                        dp[i][j][k] = 0;
                    } else if (i == 0 && j == 0) {
                        dp[i][j][k] = max(dp[i][j][k - 1], 0);
                    } else if (i == 0 && k == 0) {
                        dp[i][j][k] = max(dp[i][j - 1][k], 0);
                    } else if (j == 0 && k == 0) {
                        dp[i][j][k] = max(dp[i - 1][j][k], 0);
                    } else if (i == 0) {
                        dp[i][j][k] = max(dp[i][j - 1][k], dp[i][j][k - 1]);
                    } else if (j == 0) {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j][k - 1]);
                    } else if (k == 0) {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
                    } else {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
                    }
                }
            }
        }
    }

    cout << dp[a - 1][b - 1][c - 1];
}
