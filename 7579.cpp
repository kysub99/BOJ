#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std; 
#define MAX 

struct APP {
	int m;//크기
	int c;//비용
};

int N, M;
APP app[101];
int dp[101][10001];//앱, 비용

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		cin >> app[i].m;
	}
	for (int i = 1;i <= N;i++) {
		cin >> app[i].c;
	}
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j < 10001;j++) {
			dp[i][j] = dp[i - 1][j];
			if (app[i].c <= j) {//할당 가능
				dp[i][j] = max(dp[i][j], dp[i - 1][j - app[i].c] + app[i].m);
			}
		}
	}
	for (int j = 1;j < 10001;j++) {
		if (dp[N][j] >= M) {
			cout << j;
			break;
		}
	}

	return 0;
}