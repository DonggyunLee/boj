#include <stdio.h>
#define MOD 1000003

typedef struct List {
	typedef struct Node {
		Node *next;
		int cost;
		int exist;
		Node() :cost(0) {
			next = nullptr;
		}
	};
	Node *head, *tail;
	int size;
	List() :size(0) {
		head = new Node();
		tail = new Node();
	}
	void push(int cost) {
		Node *newnode = new Node();
		newnode->cost = cost;
		if (head->next == nullptr) {
			head->next = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = tail->next;
		}
		size++;
	}
	bool find(int a) {
		Node *tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
			if (tmp->cost == a) return true;
		}
		return false;
	}
	void clear() {
		Node *tmp = head;
		while (tmp->next != nullptr) {
			Node *del = tmp->next;
			tmp->next = del->next;
			delete del;
		}
	}
};
List table[MOD];

int N, M;
inline int hashing(int a) {
	if (a < 0) 
		a = -a;
	int ret=0;
	ret = a%MOD;
	return ret;
}
int main() {
	freopen("1920.txt", "r", stdin);
	scanf("%d", &N);
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		table[hashing(temp)].push(temp);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		printf("%d\n", table[hashing(temp)].find(temp));
	}
}