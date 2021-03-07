#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string word[2];
	int a = 0, b = 0;

	cin >> word[0] >> word[1];

	for (int i = 0; word[0][i] != '\0'; i++) a++;
	for (int i = 0; word[1][i] != '\0'; i++) b++;

	int dp[a][b];

	for (int j = 0; j < b; j++) {
		for (int i = 0; i < a; i++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < b; i++) {
		if (word[0][0] == word[1][i]) dp[0][i] = 1;
	}

	for (int i = 0; i < a; i++) {
		if (word[1][0] == word[0][i]) dp[i][0] = 1;
	}

	for (int j = 1; j < b; j++) {
		for (int i = 1; i < a; i++) {
			if (word[0][i] == word[1][j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[a - 1][b - 1];
}
