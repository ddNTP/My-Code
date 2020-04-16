#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 105, inf = 0x3f3f3f3f;
int g[N][N];
int vis[N], dis[N], cnt[N];
int m, n;
void isunique(){
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	dis[1] = 0;
	int ans =0;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]&&dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		ans += dis[u];
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				if (dis[j] == g[u][j])cnt[j]++;
				else if (dis[j] > g[u][j]) {
					cnt[j] = 1;
					dis[j] = g[u][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] > 1) {
			printf("Not Unique!\n");
			return;
		}
	printf("%d\n", ans);

}
int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(g, inf, sizeof(g));
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u][v] = g[v][u] = w;
		}
		isunique();
	}
	system("pause");
	return 0;
}