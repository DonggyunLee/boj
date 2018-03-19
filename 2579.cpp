#include <iostream>
using namespace std;

int N, tmp;
int dp[301][2];

inline int _max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0,tmp=0;
	cin >> N;
	cin >> tmp;
	dp[1][0] = tmp;//ÇÑÄ­ ¿Ã¶ó¿È
	dp[1][1] = tmp;//µÎÄ­ ¿Ã¶ó¿È
	for (int i = 2; i <= N; i++) {
		cin >> tmp;
		dp[i][0] = dp[i - 1][1] + tmp;
		dp[i][1] = _max(dp[i - 2][0], dp[i - 2][1]) + tmp;
	}
	cout << _max(dp[N][0], dp[N][1]) << '\n';

	return 0;
}