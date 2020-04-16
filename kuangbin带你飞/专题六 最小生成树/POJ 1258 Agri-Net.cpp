#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 105, inf = 0x3f3f3f3f;
int n;
int g[N][N];
int vis[N], d[N];
void prim() {
	memset(vis, 0, sizeof(vis));
	memset(d, inf, sizeof(d));
	d[1] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && d[j] < minn) {
				u = j;
				minn = d[j];
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		ans += d[u];
		for (int j = 1; j <= n; j++) 
			if(!vis[j])
				d[j] = min(d[j], g[u][j]);
	}
	cout << ans << endl;
}
int main() {
	while (scanf("%d",&n)!=EOF) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> g[i][j];
		prim();
	}
	system("pause");
	return 0;
}