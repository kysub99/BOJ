#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	string name;
	map<string, int> mp;
	for (int i = 0;i < n;i++) {
		cin >> name;
		mp[name]++;
	}
	int cnt = 0;
	vector<string> res;
	for (int i = 0;i < m;i++) {
		cin >> name;
		if (mp[name] == 1) {
			cnt++;
			res.push_back(name);
		}
	}
	sort(res.begin(), res.end());
	cout << cnt << "\n";
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << "\n";
	}
}