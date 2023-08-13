#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int sum[26][200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int q;
	cin >> s >> q;
	for (int i = 0;i < 26;i++) {
		sum[i][0] = 0;
		for (int j = 0;j < s.size();j++) {
			if (s[j] - 'a' == i) {
				sum[i][j + 1] = sum[i][j] + 1;//0����j���� ������ j+1�� ����
			}
			else
				sum[i][j + 1] = sum[i][j];
		}
	}
	for (int i = 0;i < q;i++) {
		char a;
		int l, r;
		cin >> a >> l >> r;
		int temp = a - 'a';
		cout << sum[temp][r + 1] - sum[temp][l] << "\n";
	}
}