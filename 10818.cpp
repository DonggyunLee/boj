#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, minans = 987654321, maxans = -987654321, tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		maxans = max(tmp, maxans);
		minans = min(tmp, minans);
	}
	cout << minans << " " << maxans << '\n';

	return 0;
}