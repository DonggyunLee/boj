#include <iostream>
using namespace std;

int N, Q;
int dp[301][301][11];

int main() {
	//freopen("14846input.txt", "r", stdin);
	scanf("%d", &N);
	int tmp;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &tmp);
			dp[i][j][tmp] = dp[i - 1][j][tmp] + dp[i][j - 1][tmp] - dp[i - 1][j - 1][tmp] + 1;
			for (int k = 1; k <= 10; k++)
				if (k != tmp)
					dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
		}
	scanf("%d", &Q);
	int x1, y1, x2, y2;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int sum = 0;
		for (int j = 1; j <= 10; j++) {
			if (dp[x2][y2][j] - dp[x2][y1 - 1][j] - dp[x1 - 1][y2][j] + dp[x1 - 1][y1 - 1][j] != 0)
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}