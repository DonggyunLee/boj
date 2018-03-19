#include <iostream>
using namespace std;

#define ll long long

int N;
int map[101][101];
ll dp[101][101];
bool visit[101][101];

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	bool first = true;
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (i == N && j == N) continue;
			if (first) {
				if (i + map[i][j] <= N) {
					visit[i + map[i][j]][j] = true;
					dp[i + map[i][j]][j] += dp[i][j];
				}
				if (j + map[i][j] <= N) {
					visit[i][j + map[i][j]] = true;
					dp[i][j + map[i][j]] += dp[i][j];
				}
				first = false;
			}
			if (visit[i][j]) {
				if (i + map[i][j] <= N) {
					visit[i + map[i][j]][j] = true;
					dp[i + map[i][j]][j] += dp[i][j];
				}
				if (j + map[i][j] <= N) {
					visit[i][j + map[i][j]] = true;
					dp[i][j + map[i][j]] += dp[i][j];
				}
			}
		}
	cout << dp[N][N] << '\n';

	return 0;
}