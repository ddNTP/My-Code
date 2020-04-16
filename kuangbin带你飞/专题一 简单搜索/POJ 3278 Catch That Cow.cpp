#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;
int st[100001] = { 0 };
int main() {
	int n, k;
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	queue<int>q;
	q.push(n);
	int lev = 0;
	bool flag = false;
	while (!q.empty()) {
		int n = q.size();
		lev++;
		for (int i = 0; i < n; i++) {
			int t = q.front();
			q.pop();
			int t1 = t - 1;
			if (t1 == k) {
				flag = true;
				break;
			}
			else if (t1 > 0 && t1<=100000&&!st[t1]) {
				q.push(t1);
				st[t1] = 1;
			}
			t1 = t + 1;
			if (t1 == k) {
				flag = true;
				break;
			}
			if (t1 <= 100000 && !st[t1]) {
				q.push(t1);
				st[t1] = 1;
			}
			t1 = t * 2;
			if (t1 == k) {
				flag = true;
				break;
			}
			if (t1 <= 100000 && t1 > 0 && !st[t1]) {
				q.push(t1);
				st[t1] = 1;
			}
		}
		if (flag)break;
	}
	cout << lev;
	system("pause");
	return 0;
}