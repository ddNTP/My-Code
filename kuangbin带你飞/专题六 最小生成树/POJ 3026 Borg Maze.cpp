#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 55, M = 105, inf = 0x3f3f3f3f;
char g[N][N];
int id;
int m, n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct Node
{
	int x, y, d;
	Node() :x(0), y(0), d(0) {}
	Node(int i, int j, int k) :x(i), y(j), d(k) {}
}node[M];
int mp[N][N];
int graph[M][M];
int vis[N][N];
void bfs() {
	for (int i = 1; i <= id; i++) {
		memset(vis, 0, sizeof(vis));
		queue<Node>q;
		q.push(node[i]);
		vis[node[i].x][node[i].y] = 1;
		while (!q.empty()) {
			Node t = q.front();
			q.pop();
			int tt = mp[t.x][t.y];
			if (tt)
				graph[tt][i] = graph[i][tt] = t.d;
			for (int j = 0; j < 4; j++) {
				int fx = t.x + dx[j];
				int fy = t.y + dy[j];
				if (fx >= 0 && fy >= 0 && fx < m && fy < n && !vis[fx][fy] && g[fx][fy] != '#') {

					q.push(Node(fx, fy, t.d + 1));
					vis[fx][fy] = 1;
				}
			}
		}
	}
}
int d[M];
int pvis[M];
void prim() {
	memset(d, inf, sizeof(d));
	memset(pvis, 0, sizeof(pvis));
	d[1] = 0;
	int ans = 0;
	for (int i = 0; i < id; i++) {
		int u = -1, minn = inf;
		for (int j = 1; j <= id; j++) {
			if (!pvis[j] && d[j] < minn) {
				minn = d[j];
				u = j;
			}
		}
		if (u == -1)break;
		pvis[u] = 1;
		ans += d[u];
		for (int j = 1; j <= id; j++)
			if (!pvis[j])d[j] = min(d[j], graph[u][j]);
	}
	printf("%d\n", ans);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(mp, 0, sizeof(mp));
		cin >> n >> m;
		gets_s(g[0]);
		id = 0;
		for (int i = 0; i < m; i++)gets_s(g[i]);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (g[i][j] == 'A' || g[i][j] == 'S') {
					node[++id].x = i;
					node[id].y = j;
					mp[i][j] = id;
				}
		bfs();
		prim();
	}
	system("pause");
	return 0;
}