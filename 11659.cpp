#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n + 1);
	vector<int> sum(n + 1);
	sum[0] = 0;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 1;i <= m;i++) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
}