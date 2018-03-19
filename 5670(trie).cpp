#include <iostream>
using namespace std;

int N;
char ch[100000][81];
bool first;

struct Trie {
	Trie *child[26];
	bool term;
	int size;
	Trie() :term(false), size(0) { for (int i = 0; i < 26; i++) child[i] = nullptr; }
	~Trie() {
		for (int i = 0; i < 26; i++) delete child[i];
	}
	void insert(char *str) {
		if (*str == 0)
			term = true;
		else {
			int cur = *str - 'a';
			if (child[cur] == nullptr) {
				child[cur] = new Trie();
				size++;
			}
			child[cur]->insert(str + 1);
		}
	}
	int find(char *str, int cost) {
		if (*str == 0) return cost;
		int cur = *str - 'a';
		if (first) {
			cost++;
			first = false;
		}
		else if (term || size > 1) cost++;
		return child[cur]->find(str + 1, cost);
	}
};

int main() {
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);

	while (cin >> N) {
		Trie *root = new Trie();
		for (int i = 0; i < N; i++){
			cin >> ch[i];
			root->insert(ch[i]);
		}
	
		double ans = 0;
		for (int i = 0; i < N; i++) {
			first = true;
			ans += root->find(ch[i], 0);
		}
		cout << ans / N << '\n';
		delete root;
	}

	return 0;
}