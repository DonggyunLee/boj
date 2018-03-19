#include <iostream>
#include <algorithm>
using namespace std;

int N,ans;
int arr[10001];
int dp[10001];

void dfs(int start, int end, int cost) {
	if (cost >= ans) return;
	if (start == end) {
		ans = min(ans,cost);
		return;
	}
	dp[start] = cost;
	for (int i = start + arr[start]; i <= N; i+=arr[start]) {
		if (dp[i] > cost+1) {
			dfs(i, end, cost + 1);
		}
	}
	for (int i = start - arr[start]; i >= 1; i -= arr[start]) {
		if (dp[i] > cost+1) {
			dfs(i, end, cost + 1);
		}
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	int a, b;
	ans = 987654321;
	for (int i = 0; i < 10001; i++) dp[i] = 987654321;
	cin >> a >> b;
	dfs(a, b, 0);
	if (ans == 987654321) cout << "-1" << '\n';
	else cout << ans << '\n';

	return 0;
}