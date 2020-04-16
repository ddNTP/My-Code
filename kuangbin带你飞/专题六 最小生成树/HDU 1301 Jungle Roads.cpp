#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
const int N = 30, inf = 0x3f3f3f3f;
int g[N][N], d[N], vis[N], n;
void prim() {
	mm(vis, 0);
	mm(d, inf);
	d[0] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && d[j] < minn) {
				minn = d[j];
				u = j;
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		ans += d[u];
		for (int j = 0; j < n; j++) 
			if (!vis[j])d[j] = min(d[j], g[u][j]);
	}
	cout << ans << endl;
}
int main() {
	while (cin>>n) {
		if (n == 0)break;
		mm(g, inf);
		char t;
		for (int i = 0; i < n - 1; i++) {
			cin >> t;
			int m;
			cin >> m;
			char c;
			for (int j = 0; j < m; j++) {
				int w;
				cin >> c >> w;
				g[c - 'A'][t-'A'] = g[t-'A'][c - 'A'] = w;
			}
		}
		prim();
	}
	system("pause");
	return 0;
}