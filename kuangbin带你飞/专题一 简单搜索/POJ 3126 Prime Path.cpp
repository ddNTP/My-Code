#include<iostream>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<cstring>
using namespace std;
bool isprime(int n) {
	if (n < 2)return false;
	int t = sqrt(n);
	for (int i = 2; i <= t; i++)
		if (n%i == 0)return false;
	return true;
}
int p[10000] = { 0 };
int vis[10000] = { 0 };
int num[4];
void tos(int x) {
	for (int i = 0; i < 4; i++) {
		num[3 - i] = x % 10;
		x /= 10;
	}
}
int tonum() {
	int res = 0;
	for (int i = 0; i < 4; i++)
		res = res * 10 + num[i];
	return res;
}
int bfs(int x, int y) {
	if (x == y)return 0;
	memset(vis, 0, sizeof(vis));
	queue<int>q;
	q.push(x);
	vis[x] = 1;
	int lev = 0;
	while (!q.empty()) {
		int n = q.size();
		lev++;
		for (int i = 0; i < n; i++) {
			int t = q.front();
			q.pop();
			tos(t);
			for (int j = 0; j < 4; j++) {
				int t1 = num[j];
				for (int k = j == 0 ? 1 : 0; k <= 9; k++) {
					num[j] = k;
					int t2 = tonum();
					if (t2 == y) return lev;
					if (!vis[t2] && p[t2]) {
						vis[t2] = 1;
						q.push(t2);
					}
				}
				num[j] = t1;
			}
		}
	}
	return -1;
}
int main() {
	int n;
	for (int i = 1000; i < 10000; i++)
		if (isprime(i))p[i] = 1;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		int res = bfs(x, y);
		if (res == -1)printf("Impossible\n");
		else printf("%d\n", res);
	}
	system("pause");
	return 0;
}