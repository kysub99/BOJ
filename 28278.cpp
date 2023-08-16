#include <iostream>
using namespace std;

class stack {
private:
	int* arr;
	int idx;
public:
	stack(int n) {
		arr = new int[n];
		idx = -1;
	}
	int size() {
		return idx + 1;
	}
	bool empty() {
		return size()==0;
	}
	void push(int x) {
		idx++;
		arr[idx] = x;
	}
	int top() {
		if (empty())
			return -1;
		return arr[idx];
	}
	int pop() {
		if (empty())
			return -1;
		idx--;
		return arr[idx + 1];
	}

	
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack st(n);
	for (int i = 0;i < n;i++) {
		int op;
		cin >> op;
		switch (op) {
		case 1:
			int x;
			cin >> x;
			st.push(x);
			break;
		case 2:
			cout << st.pop() << "\n";
			break;
		case 3:
			cout << st.size() << "\n";
			break;
		case 4:
			cout << st.empty() << "\n";
			break;
		default:
			cout << st.top() << "\n";
			break;
		}
	}
}