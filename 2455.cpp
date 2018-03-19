#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int out,in, maxans=0, cur=0;
	for (int i = 0; i < 4; i++) {
		cin >> out >> in;
		cur -= out;
		maxans = max(cur, maxans);
		cur += in;
		maxans = max(cur, maxans);
	}
	cout << maxans << '\n';

	return 0;
}