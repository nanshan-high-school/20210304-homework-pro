#include <iostream>
using namespace std;

int main() {
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	string A,B,C;
	string input;
	A += 'a';
	cin >> input;
	A += input;
	B += 'a';
	cin >> input;
	B += input;
	C += 'a';
	cin >> input;
	C += input;
	int dp[num1 + 1][num2 + 1][num3 + 1];
	for (int i = 0; i < num1 + 1; i++) {
		for (int j = 0; j < num2 + 1; j++) {
			for (int k = 0; k < num3 + 1; k++) {
				dp[i][j][k] = 0;
			}
			
		}
	}

	for (int i = 1; i < num1 + 1; i++) {
		for (int j = 1; j < num2 + 1; j++) {
			for (int k = 1; k < num3 + 1; k++) {
				if (A[i] == B[j] && B[j] == C[k]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				} else {
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
					dp[i][j][k] = max(dp[i][j][k - 1], dp[i][j][k]);
				}
			}
		}
	}
	cout << dp[num1][num2][num3];
}
