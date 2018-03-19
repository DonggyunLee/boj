#include <stdio.h>

int N, M;
int map[1025][1025];
int dp[1025][1025];

int main() {
	freopen("11660input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i-1][j-1]+ map[i][j];
		}
	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
	}
	return 0;
}