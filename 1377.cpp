#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> arr;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end());
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(arr[i].second - i, ans);
	cout << ans + 1 << '\n';

	return 0;
}