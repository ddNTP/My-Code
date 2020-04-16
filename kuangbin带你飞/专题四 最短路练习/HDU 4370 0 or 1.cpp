#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 305, inf = 0x3f3f3f3f;
int graph[N][N];
int n;
int dis[N], vis[N];
void dij(int s) {
	memset(dis, inf, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		if (i == s)continue;
		dis[i] = graph[s][i];
	}
	while (1) {
		int u = -1, minn = inf;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]&&dis[i] < minn) {
				u = i;
				minn = dis[i];
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && dis[u] + graph[u][i] < dis[i])
				dis[i] = dis[u] + graph[u][i];
		}
	}
}
int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++)
				scanf("%d", &graph[i][j]);
		dij(1);
		int t1 = dis[1], t2 = dis[n];
		dij(n);
		int t3 = dis[n];
		cout << min(t1 + t3, t2) << endl;
	}
	system("pause");
	return 0;
}