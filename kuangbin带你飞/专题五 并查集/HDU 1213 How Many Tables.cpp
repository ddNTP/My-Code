#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1005;
int fa[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
void unio(int x, int y) {
	int fx = findfa(x);
	int fy = findfa(y);
	fa[fx] = fy;
}
int root[N];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		memset(root, 0, sizeof(root));
		for (int i = 0; i < m; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			unio(t1, t2);
		}
		for (int i = 1; i <= n; i++)
			root[findfa(i)] = 1;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += root[i];
		cout << ans << endl;
	}
	system("pause");
	return 0;
}