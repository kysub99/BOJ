#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> wood;
int res = 0;

void divide(int s, int e) {
	if (s == e)
		return;
	long long sum = 0;
	int mid = (s + e) / 2;
	for (int i = 0;i < n;i++) {
		int temp = wood[i] - mid;
		if (temp > 0) {
			sum += temp;
		}
	}
	if (sum >= m) {// ���� �÷��� ��
		res = max(res, mid);
		divide(mid + 1, e);
	}
	else {// ���� ����-���� ������ ��
		divide(s, mid);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	wood.resize(n);
	for (int i = 0;i < n;i++) {
		cin >> wood[i];
	}
	divide(0, 1000000001);
	cout << res;
}