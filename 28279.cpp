#include <iostream>
using namespace std;

class deque {
private:
	int* arr;
	int f;
	int b;
public:
	deque(int n) {
		arr = new int[2 * n];
		f = n - 1;
		b = n;
	}
	int size() {
		return b - f - 1;
	}
	bool empty() {
		return size() == 0;
	}
	void pushFront(int x) {
		arr[f] = x;
		f--;
	}
	void pushBack(int x) {
		arr[b] = x;
		b++;
	}
	int popFront() {
		if (empty())
			return -1;
		f++;
		return arr[f];
	}
	int popBack() {
		if (empty())
			return -1;
		b--;
		return arr[b];
	}
	int topFront() {
		if (empty())
			return -1;
		return arr[f+1];
	}
	int topBack() {
		if (empty())
			return -1;
		return arr[b-1];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	deque dq(n);
	for (int i = 0;i < n;i++) {
		int c, x;
		cin >> c;
		switch (c){
		case 1:
			cin >> x;
			dq.pushFront(x);
			break;
		case 2:
			cin >> x;
			dq.pushBack(x);
			break;
		case 3:
			cout << dq.popFront() << "\n";
			break;
		case 4:
			cout << dq.popBack() << "\n";
			break;
		case 5:
			cout << dq.size() << "\n";
			break;
		case 6:
			cout << dq.empty() << "\n";
			break;
		case 7:
			cout << dq.topFront() << "\n";
			break;
		default:
			cout << dq.topBack() << "\n";
			break;
		}
	}
}