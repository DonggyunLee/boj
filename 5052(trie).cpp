#include <iostream>
using namespace std;

struct Trie {
	Trie *child[10];
	bool term;
	Trie(){
		for (int i = 0; i<10; i++) child[i] = nullptr;
		term = false;
	}
	void insert(char* key) {
		if (*key == 0)
			term = true;
		else {
			int cur = *key -'0';
			if (child[cur] == nullptr)
				child[cur] = new Trie();
			child[cur]->insert(key + 1);
		}
	}
	bool find(char* key) {
		if (*key == 0)
			return false;
		if (term)
			return true;
		int cur = *key - '0';
		return child[cur]->find(key + 1);
	}
};
int t, n;
char a[10000][11];

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i<n; i++)
			cin >> a[i];
		Trie *root = new Trie;
		bool r = false;
		for (int i = 0; i<n; i++)
			root->insert(a[i]);
		for (int i = 0; i<n; i++) 
			if (root->find(a[i])) 
				r = true;
		r ? cout << "NO" << '\n' : cout << "YES" << '\n';
		delete root;
	}
	return 0;
}
