#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int N;
ll ans;
int arr[500000];
vector<int> tmp;

void merge(int s, int d) {
	if (s == d) return;
	int mid = (s + d) / 2;
	merge(s, mid);
	merge(mid + 1, d);
	tmp.clear();
	int i = s, j = mid + 1;
	while (i <= mid && j <= d) {
		if (arr[i] <= arr[j]) {
			tmp.push_back(arr[i]);
			i++;
		}
		else {
			tmp.push_back(arr[j]);
			ans += (mid + 1 - i);
			j++;
		}
	}
	while (i <= mid) tmp.push_back(arr[i++]);
	while (j <= d) tmp.push_back(arr[j++]);
	for (int i = s, j = 0; i <= d; i++, j++) {
		arr[i] = tmp[j];
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	merge(0, N - 1);
	cout << ans << '\n';

	return 0;
}