#include <iostream>
using namespace std;
#define ll long long

ll N, K;
int Q;

ll lca(ll a, ll b) {
	ll ret = 0;
	if (a < b) swap(a, b);
	while (a > b) {
		a = (a + K - 2) / K;
		ret++;
	}
	while (a != b) {
		b = (b + K - 2) / K;
		ret++;
		if (a == b) return ret;
		a = (a + K - 2) / K;
		ret++;
	}
	return ret;
}
int main() {
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> K >> Q;
	ll t1, t2;
	if (K == 1) {
		for (int i = 0; i < Q; i++) {
			cin >> t1 >> t2;
			if (t1 < t2) swap(t1, t2);
			cout << t1 - t2 << '\n';
		}
		return 0;
	}
	for (int i = 0; i < Q; i++) {
		cin >> t1 >> t2;
		cout << lca(t1, t2) << '\n';
	}

	return 0;
}