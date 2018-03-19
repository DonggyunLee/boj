#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct Person {
	string name;
	int kor, eng, math;
};
bool cmp(const Person& u, const Person& v) {
	if (u.kor > v.kor)
		return true;
	else if (u.kor == v.kor) {
		if (u.eng < v.eng) {
			return true;
		}
		else if (u.eng == v.eng) {
			if (u.math > v.math)
				return true;
			else if (u.math == v.math) {
				return u.name < v.name;
			}
		}
	}
	return false;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<Person> arr(n);
	for (int i = 0; i < n; i++) 
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;
	
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++) 
		cout << arr[i].name << '\n';

	return 0;
}
