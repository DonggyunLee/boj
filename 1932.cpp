#include <iostream>
using namespace std;

int dp[501][501];
int N;

inline int _max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int temp, ans=0;
	cin >> dp[1][1];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> temp;
			dp[i][j] = _max(dp[i - 1][j - 1], dp[i - 1][j]) + temp;
			ans = _max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';

	return 0;
}