#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, num;
	cin >> n;
	stack<pair<int, int>> st;// ��, �ε���
	vector<int> res(n);
	for (int i = 0;i < n;i++) {
		cin >> num;
		while (!st.empty() && st.top().first < num) {
			res[st.top().second] = num;
			st.pop();
		}
		st.push({ num,i });
	}
	while (!st.empty() && st.top().first < 1000001) {//��ū�� ���� �͵� ó��
		res[st.top().second] = -1;
		st.pop();
	}
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << " ";
	}
}