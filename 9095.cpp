#include <iostream>
using namespace std;

int N, ans;

void dfs(int cost) {
	if (cost > N) return;
	if (cost == N) {
		ans++;
		return;
	}
	dfs(cost + 1);
	dfs(cost + 2);
	dfs(cost + 3);
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N;
		ans = 0;
		dfs(0);
		cout << ans << '\n';
	}

	return 0;
}