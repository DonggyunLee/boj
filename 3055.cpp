#include <iostream>
using namespace std;

typedef struct List {
	typedef struct Node {
		int x, y;
		Node *next;
		Node():y(0),x(0) {
			next = nullptr;
		}
	};
	Node *head, *tail;
	int size;
	List() :size(0) {
		head = new Node();
		tail = new Node();
	}
	void push(int y, int x) {
		Node *newnode = new Node();
		newnode->x = x;
		newnode->y = y;
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
	void pop() {
		if (size==0) return;
		Node *del = head->next;
		head->next = del->next;
		delete del;
		size--;
	}
	bool isEmpty() {
		if (size==0) return true;
		return false;
	}
};
int nW;
int R, C;
char map[51][51];
int ans;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void init() {
	nW = 0;
	ans = 987654321;
}
inline int min(int a, int b) {
	return a < b ? a : b;
}
inline bool safe(int h, int w) {
	return h >= 0 && h < R&&w >= 0 && w < C;
}
void bfs(int sX, int sY, int *wX, int *wY) {
	List *S = new List();
	S->push(sY, sX);
	List *W = new List[nW];
	for (int i = 0; i < nW; i++)
		W[i].push(wY[i], wX[i]);
	int count = 0;
	while (!S->isEmpty()) {
		int n = S->size;
		for (int i = 0; i < n; i++) {
			int height = S->head->next->y;
			int width = S->head->next->x;
			S->pop();
			if (map[height][width] == '*') continue;
			for (int i = 0; i < 4; i++) {
				int tmpY = height + dy[i];
				int tmpX = width + dx[i];
				if (safe(tmpY, tmpX) && map[tmpY][tmpX]=='D') {
					ans = count+1;
					return;
				}
				else if (safe(tmpY, tmpX) && map[tmpY][tmpX] == '.') {
					map[tmpY][tmpX] = 'S';
					S->push(tmpY, tmpX);
				}
			}
		}
		for (int i = 0; i < nW; i++) {
			n = W[i].size;
			for (int k = 0; k < n; k++) {
				int height = W[i].head->next->y;
				int width = W[i].head->next->x;
				W[i].pop();
				for (int j = 0; j < 4; j++) {
					int tmpY = height + dy[j];
					int tmpX = width + dx[j];
					if (safe(tmpY, tmpX) && (map[tmpY][tmpX] == 'S' || map[tmpY][tmpX] == '.')) {
						map[tmpY][tmpX] = '*';
						W[i].push(tmpY, tmpX);
					}
				}
			}
		}
		count++;
	}
	
}
int main() {
	freopen("3055input.txt", "r", stdin);
	init();
	cin >> R >> C;
	int wX[2500] = { 0, }, wY[2500] = { 0, };
	int sX, sY;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				wY[nW] = i;
				wX[nW++] = j;
			}
			else if (map[i][j] == 'S') sY = i, sX = j;
		}
	bfs(sX, sY, wX, wY);
	if (ans == 987654321) cout << "KAKTUS" << endl;
	else cout << ans << endl;

	return 0;
}