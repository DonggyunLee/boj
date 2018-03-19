#include <iostream>
using namespace std;



int main() {
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		char str[61] = { 0, };
		cin >> str;
		char pr[61] = { 0, }, ho[61] = { 0, }, po[61] = { 0, }, pa[61] = { 0, };
		cout << "URL #" << t << '\n';
		int i, idx;
		for (i = 0,idx=0; str[i]; i++) {
			if (str[i] == ':') {
				i += 3;
				break;;
			}
			pr[idx++] = str[i];
		}
		bool port = false, path = false;
		for (idx=0; str[i]; i++) {
			if (str[i] == ':') {
				i++;
				port = true;
				break;
			}
			else if (str[i] == '/') {
				i++;
				path = true;
				break;
			}
			ho[idx++] = str[i];
		}
		if (port) {
			for (idx = 0; str[i]; i++) {
				if (str[i] == '/') {
					i++;
					path = true;
					break;
				}
				po[idx++] = str[i];
			}
		}
		if (path) {
			for (idx = 0; str[i]; i++) {
				pa[idx++] = str[i];
			}
		}
		cout << "Protocol = " << pr << '\n';
		cout << "Host     = " << ho << '\n';
		cout << "Port     = ";
		if (port) cout << po << '\n';
		else cout << "<default>\n";
		cout << "Path     = ";
		if (path) cout << pa << '\n';
		else cout << "<default>\n";
		cout << '\n';
	}


	return 0;
}
