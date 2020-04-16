#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
const int N = 105, inf = 0x3f3f3f3f;
int g[N][N], d[N], vis[N], n;
void prim() {
	mm(vis, 0);
	mm(d, inf);
	d[1] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]&&d[j] < minn) {
				u = j;
				minn = d[j];
			}
		}
		if (u == -1)break;
		ans += d[u];
		vis[u] = 1;
		for (int j = 1; j <= n; j++) 
			if (!vis[j])d[j] = min(d[j], g[u][j]);
	}
	cout << ans << endl;
}
int main() {
	
	while (scanf("%d", &n)) {
		if (n == 0)break;
		mm(g, inf);
		int m = n * (n - 1) / 2;
		for (int i = 0; i < m; i++) {
			int t1, t2, t3;
			scanf("%d%d%d", &t1, &t2, &t3);
			g[t1][t2] = g[t2][t1] = t3;
		}
		prim();
	}
	system("pause");
	return 0;
}