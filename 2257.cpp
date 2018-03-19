#include <iostream>
using namespace std;

char str[101];
int i;

int trans(char a) {
	if (a == 'H') return 1;
	else if (a == 'C') return 12;
	else if (a == 'O') return 16;
}
int solve() {
	i++;
	int ans = 0;
	for (; str[i]; i++) {
		if (str[i] == 'H' || str[i] == 'C' || str[i] == 'O') {
			ans += trans(str[i]);
		}
		else if (str[i] >= '2' && str[i] <= '9') {
			ans += (trans(str[i - 1]) * (str[i] - '0' - 1));
		}
		else if (str[i] == '(') {
			int tmp = solve();
			if (str[i] >= '2' &&str[i] <= '9') {
				ans += (tmp * (str[i] - '0'));
			}
			else {
				ans += tmp;
				i--;
			}
		}
		else if (str[i] == ')') {
			i++;
			return ans;
		}
	}
}
int main() {
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> str;
	int ans = 0;
	for (i = 0; str[i]; i++) {
		if (str[i] == 'H' || str[i] == 'C' || str[i] == 'O') {
			ans += trans(str[i]);
		}
		else if (str[i] >= '2' && str[i] <= '9') {
			ans += (trans(str[i - 1]) * (str[i] - '0' - 1));
		}
		else if (str[i] == '(') {
			int tmp = solve();
			if (str[i] >= '2' &&str[i] <= '9') {
				ans += (tmp * (str[i] - '0'));
			}
			else {
				ans += tmp;
				i--;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
