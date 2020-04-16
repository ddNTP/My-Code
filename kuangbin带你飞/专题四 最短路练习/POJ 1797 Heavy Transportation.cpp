#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
int graph[1005][1005];
int w[1005];
int vis[1005];
const int inf = 0x3f3f3f3f;
void dij() {
	memset(w, 0, sizeof(w));
	memset(vis, 0, sizeof(vis));
	w[1] = inf;
	while (1) {
		int u = -1, maxn = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && w[i] > maxn) {
				u = i;
				maxn = w[i];
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		for (int i = 1; i <= n; i++) 
			w[i] = max(w[i], min(w[u], graph[u][i]));
	}
}
int main() {
	int k;
	cin >> k;
	int id = 1;
	while (k--) {
		memset(graph, 0, sizeof(graph));
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			if (t3 > graph[t1][t2]) 
				graph[t1][t2] = graph[t2][t1] = t3;
		}
		dij();
		printf("Scenario #%d:\n", id++);
		printf("%d\n\n", w[n]);
	}
	system("pause");
	return 0;
}