#include <iostream>
#include <string.h>
using namespace std;

struct Trie {
	Trie *next[26];
	bool finish;
	Trie() {
		finish = false;
		for (int i = 0; i < 26; i++) next[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) delete next[i];
	}
	void insert(char *str) {
		if (*str == 0)
			finish = true;
		else {
			int cur = *str - 'a';
			if (next[cur] == nullptr) next[cur] = new Trie();
			next[cur]->insert(str + 1);
		}
	}
	bool find(char *str) {
		int cur = *str - 'a';
		if (finish) return true;
		if (*str == 0 || next[cur] == nullptr) return false;
		return next[cur]->find(str + 1);
	}
};

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		while (getchar() != '\n');
		char input[20000] = { 0, };
		cin.getline(input, sizeof(input));
		Trie *root = new Trie();
		while (1) {
			char animal[110] = { 0, }, tmp[6] = { 0, }, voice[110] = { 0, };
			scanf("%s %s %s", animal, tmp, voice);
			if (strcmp(tmp, "goes")) break;
			root->insert(voice);
		}
		char *ptr = strtok(input, " ");
		while (ptr) {
			if (root->find(ptr)) {
				ptr = strtok(NULL, " ");
			}
			else {
				cout << ptr << " ";
				ptr = strtok(NULL, " ");
			}
		}
		puts("");
		delete root;
	}

	return 0;
}