//#include <iostream>
//using namespace std;
//#define N 19
//
//int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//int _dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//int _dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//
//int map[N][N];
//int ansX, ansY, ans;
//
//void init() {
//	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) map[i][j] = 0;
//	ansX = ansY = ans = 0;
//}
//bool safe(int height, int width) {
//	return height >= 0 && height < N && width >= 0 && width < N;
//}
//bool check(int height, int width, int type) {
//	for (int j = 0; j < 8; j++) dx[j] = _dx[j], dy[j] = _dy[j];
//	for (int i = 0; i < 8; i++) {
//		int h = height + dy[i];
//		int w = width + dx[i];
//		bool f = true;
//		for (int j = 0; j < 5; j++) {
//			if (safe(h, w) && map[h][w] == type) {
//				if (dx[i] > 0)w++;
//				else if (dx[i] < 0)w--;
//				if (dy[i] > 0)h++;
//				else if (dy[i] < 0)h--;
//				if (j == 4) {
//					f = false;
//					break;
//				}
//			}
//			else{
//				if (j == 4) break;
//				f = false;
//				break;
//			}
//		}
//		if (f) {
//			int tmpW=width, tmpH=height;
//			if (dx[i] > 0)tmpW--;
//			else if (dx[i] < 0)tmpW++;
//			if (dy[i] > 0)tmpH--;
//			else if (dy[i] < 0)tmpH++;
//			if (safe(tmpH, tmpW) && map[tmpH][tmpW] == type) continue;
//			if (w >= width) {
//				ans = type;
//				ansX = width + 1;
//				ansY = height + 1;
//			}
//			else {
//				if (dx[i] > 0)w--;
//				else if (dx[i] < 0)w++;
//				if (dy[i] > 0)h--;
//				else if (dy[i] < 0)h++;
//				ans = type;
//				ansX = w + 1;
//				ansY = h + 1;
//			}
//			return true;
//		}
//	}
//	return false;
//}
//int main() {
//	freopen("2615.txt", "r", stdin);
//	init();
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++) cin >> map[i][j];
//	for(int i=0;i<N;i++)
//		for (int j = 0; j < N; j++) {
//			if (map[i][j] != 0) {
//				if (check(i, j, map[i][j])) {
//					cout << ans << endl;
//					cout << ansY << " " << ansX << endl;
//					return 0;
//				}
//			}
//		}
//	cout << "0" << endl;
//}