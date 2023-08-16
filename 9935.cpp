#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string t, p;
	cin >> t >> p;
	stack<char> st;
	stack<char> temp;
	int n = t.length();
	int m = p.length();
	for (int i = 0;i < n;i++) {
		st.push(t[i]);
		if (t[i] == p[m-1]) {//�ǵ� ������ ��ġ�ϴ��� Ȯ��
			int j = m - 1;//���� ��
			while (!st.empty() && j >= 0) {
				if (st.top() == p[j]) {
					temp.push(st.top());
					st.pop();
					j--;
				}
				else {//�ٸ�
					break;
				}
			}
			if (j == -1) {//�� ��ġ - temp ���� �������
				while (!temp.empty()) {
					temp.pop();
				}
			}
			else {//�κ� ��ġ-���ÿ� �ٽ� �־���
				while (!temp.empty()) {
					st.push(temp.top());
					temp.pop();
				}
			}

		}
	}
	if (st.empty()) {
		cout << "FRULA\n";
	}
	else {
		stack<char> res;
		int len = st.size();
		for (int i = 0;i < len;i++) {
			res.push(st.top());
			st.pop();
		}
		for (int i = 0;i < len;i++) {
			cout << res.top();
			res.pop();
		}
	}
}