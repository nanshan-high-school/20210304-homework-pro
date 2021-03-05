#include <iostream>
using namespace std;

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	string A,B;
	string input;
	A += 'a';
	cin >> input;
	A += input;
	B += 'a';
	cin >> input;
	B += input;
	int dp[num1 + 1][num2 + 1];
	for (int i = 0; i < num1 + 1; i++) {
		for (int j = 0; j < num2 + 1; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i < num1 + 1; i++) {
		for (int j = 1; j < num2 + 1; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[num1][num2];

}