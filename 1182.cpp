#include <iostream>
using namespace std;

int N, S, ans;
int arr[20];

void dfs(int depth, int cost) {
	if (depth == N) {
		if (cost == S) {
			ans++;
		}
		return;
	}
	dfs(depth + 1, cost + arr[depth]);
	dfs(depth + 1, cost);
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	dfs(0, 0);
	if (S == 0) ans--;
	cout << ans << '\n';

	return 0;
}