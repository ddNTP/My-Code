#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 2e5 + 5, inf = 0x3f3f3f3f, M = 1e6 + 5, ex = 1e5 + 1;
#define mm(a,b) memset(a,b,sizeof(a))
int n, m, c;
struct edge
{
	int next, to, w;
}e[M];
int h[N], cnt;
void add(int u, int v, int w) {
	e[++cnt].next = h[u];
	e[cnt].to = v;
	e[cnt].w = w;
	h[u] = cnt;
}
int dis[N], vis[N];
struct node
{
	int d, v;
	node(int x,int y):d(x),v(y){}
	bool operator<(const node &a)const {
		return d > a.d;
	}
};
void dij() {
	mm(dis, inf);
	mm(vis, 0);
	priority_queue<node>q;
	dis[1] = 0;
	q.push(node(0, 1));
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (vis[t.v])continue;
		vis[t.v] = 1;
		for (int i = h[t.v]; i; i = e[i].next) {
			int v = e[i].to;
			int val = dis[t.v] + e[i].w;
			if (val < dis[v]) {
				dis[v] = val;
				q.push(node(val, v));
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	int cas = 1;
	while (T--) {
		cin >> n >> m >> c;
		mm(h, 0);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			int t;
			cin >> t;
			add(i, t + ex + 1, c);
			add(i, t + ex - 1, c);
			add(t + ex, i, 0);
		}
		for (int i = 0; i < m; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			add(t1, t2, t3);
			add(t2, t1, t3);
		}
		dij();
		printf("Case #%d: %d\n", cas++, dis[n] == inf ? -1 : dis[n]);
	}
	system("pause");
	return 0;
 }