#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int M = 4e5 + 5, N = 205, inf = 0x3f3f3f3f;
int n, m;
struct edge
{
	int next, to, w;
}e[M];
int h[N], cnt, w[N];
void add(int u, int v, int w) {
	e[++cnt].next = h[u];
	e[cnt].to = v;
	e[cnt].w = w;
	h[u] = cnt;
}
int vis[N], dis[N], num[N], is[N];
struct node
{
	int d, v;
	node(int x,int y):d(x),v(y){}
	bool operator<(const node &a)const {
		return d > a.d;
	}
};
void dfs(int u) {
	is[u] = 1;
	for (int i = h[u]; i; i = e[i].next) {
		int v = e[i].to;
		if (!is[v])
			dfs(v);
	}
}
void spfa() {
	priority_queue<node>q;
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	memset(num, 0, sizeof(num));
	memset(is, 0, sizeof(is));
	dis[1] = 0;
	q.push(node(0, 1));
	vis[1] = 1;
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		vis[t.v] = 0;
		for (int i = h[t.v]; i; i = e[i].next) {
			int v = e[i].to;
			int val = dis[t.v] + e[i].w;
			if (!is[v]&&val < dis[v]) {
				dis[v] = val;
				if (!vis[v]) {
					q.push(node(val, v));
					vis[v] = 1;
					if (++num[v] > N)
						dfs(v);
				}
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	int id = 1;
	while (T--) {
		memset(h, 0, sizeof(h)); 
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) 
			scanf("%d", &w[i]);
		cin >> m;
		for (int i = 0; i < m; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			add(t1, t2, pow(w[t2] - w[t1], 3));
		}
		int q;
		cin >> q;
		spfa();
		printf("Case %d:\n", id++);
		for (int i = 0; i < q; i++) {
			int t;
			cin >> t;
			if (is[t]||dis[t] < 3 || dis[t] == inf)
				printf("?\n");
			else
				printf("%d\n", dis[t]);
		}
	}
	system("pause");
	return 0;
}