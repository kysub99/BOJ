#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dp[31][15001];//������� ���Դ� 0���� ����
int warr[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int w;
	cin >> w;
	int wsum=0;
	for (int i = 1;i <= w;i++) {
		cin >> warr[i];
		wsum += warr[i];
	}
	for (int i = 0;i <= w;i++)
		dp[i][0] = 1;
	for (int i = 1;i <= w;i++) {
		for (int j = 1;j <= wsum;j++) {
			if (warr[i] > j) {//���� ���԰� ���Ϸ��� ���Ժ��� ŭ-����x
				dp[i][j] = dp[i - 1][j];
			}
			else {// ����o
				dp[i][j] = dp[i-1][j] || dp[i - 1][j - warr[i]];//�� �߸� �������� �ʾ����� �����ϸ� �����ص� ����
			}
		}
	}
	/*for (int i = 1;i <= w;i++) {
		for (int j = 1;j <= wsum;j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		bool check = true;
		for (int j = 0;j <= wsum-num;j++) {
			if (dp[w][j] && dp[w][j + num]) {//�� ���� ������ �� �� ���Կ� ���� ���� ���� �ŵ� �����ϸ� Y
				cout << "Y ";
				check = false;
				break;
			}
		}
		if (check)
			cout << "N ";
	}
}