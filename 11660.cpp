#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1025][1025];
int sum[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> arr[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1]
				- sum[i - 1][j - 1] + arr[i][j];
		}
	}
	for (int i = 0;i < m;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - sum[x1-1][y2] 
			- sum[x2][y1-1] + sum[x1-1][y1-1] << "\n";
	}
}