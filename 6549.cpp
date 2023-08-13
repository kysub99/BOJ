#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long arr[100000];
int n;

long long divide(int s, int e) {
    if (s == e) {
        return arr[s];
    }
    int min_idx = s;
    for (int i = s + 1; i <= e; i++) {
        if (arr[min_idx] > arr[i]) {
            min_idx = i;
        }
    }
    long long left_area = min_idx == s ? 0 : divide(s, min_idx - 1);
    long long right_area = min_idx == e ? 0 : divide(min_idx + 1, e);
    long long middle_area = (e - s + 1) * arr[min_idx];

    return max({ left_area, right_area, middle_area });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << divide(0, n - 1) << "\n";
    }
}
