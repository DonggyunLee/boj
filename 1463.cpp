#include <iostream>
using namespace std;

int N;
int dp[1000001];

inline int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0 || i % 3 == 0) {
			if(i%2==0 && i%3!=0) dp[i] = min(dp[i / 2],dp[i-1]) + 1;
			else if (i % 2 != 0 && i % 3 == 0) dp[i] = min(dp[i / 3],dp[i-1]) + 1;
			else dp[i] = min(dp[i-1], min(dp[i / 2], dp[i / 3])) + 1;
		}
		else dp[i] = dp[i - 1] + 1;
	}
	cout << dp[N] << '\n';

	return 0;
}