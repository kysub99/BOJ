#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	int n1 = str1.size();
	int n2 = str2.size();
	int temp = 0;
	for (int i = 0;i < n2;i++) {
		if (str1[0] == str2[i])
			temp = 1;
		dp[0][i] = temp;
	}
	temp = 0;
	for (int i = 0;i < n1;i++) {
		if (str1[i] == str2[0])
			temp = 1;
		dp[i][0] = temp;
	}
	for (int i = 1;i < n1;i++) {
		for (int j = 1;j < n2;j++) {
			if (str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	/*for (int i = 0;i < n1;i++) {
		for (int j = 0;j < n2;j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << dp[n1 - 1][n2 - 1];
}