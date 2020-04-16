#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
const int N = 1e3 + 5, M = 4e5 + 5, inf = 0x3f3f3f3f, X = 1e5 + 5;
struct edge
{
	int next, to, w;
}e[M];
int h[N], rh[N], wh[N], cnt, n, m, s, t, u[X], v[X], w[X];
void add(int head[], int u, int v, int w) {
	e[++cnt].next = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	head[u] = cnt;
}
struct node
{
	int d, v;
	node(int x,int y):d(x),v(y){}
	bool operator<(const node &a)const {
		return d > a.d;
	}
};
int vis[N], d[N], rd[N];
void dij(int head[], int start,int dis[]) {
	mm(vis, 0);
	memset(dis, inf, sizeof(d));
	dis[start] = 0;
	priority_queue<node>q;
	q.push(node(0, start));
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (vis[t.v])continue;
		vis[t.v] = 1;
		for (int i = head[t.v]; i; i = e[i].next) {
			int v = e[i].to;
			int val = dis[t.v] + e[i].w;
			if (val < dis[v]) {
				dis[v] = val;
				q.push(node(val, v));
			}
		}
	}
}
int bvis[N];
bool bfs() {
	mm(bvis, 0);
	queue<int>q;
	q.push(s);
	bvis[s] = 1;
	while (!q.empty()) {
		int tt = q.front();
		q.pop();
		for (int i = wh[tt]; i; i = e[i].next) {
			int v = e[i].to;
			if (e[i].w && !bvis[v]) {
				bvis[v] = bvis[tt] + 1;
				q.push(v);
				if (v == t)return true;
			}
			
		}
	}
	return false;
}
int dinic(int s, int flow) {
	if (s == t)return flow;
	int rest = flow, k;
	for (int i = wh[s]; i&&rest; i = e[i].next) {//i&&rest
		int v = e[i].to;
		if (bvis[v] == bvis[s] + 1&&e[i].w) {
			k = dinic(v, min(rest, e[i].w));
			if (!k)bvis[v] = 0;
			e[i].w -= k;
			e[i ^ 1].w += k;
			rest -= k;
		}
	}
	return flow - rest;
}
int main() {
	int cas;
	cin >> cas;
	while (cas--) {
		mm(h, 0);
		mm(rh, 0);
		mm(wh, 0);
		cnt = 1;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			scanf("%d %d %d", &u[i], &v[i], &w[i]);
			if (u[i] == v[i])continue;
			add(h, u[i], v[i], w[i]);
			add(rh, v[i], u[i], w[i]);
		}
		cin >> s >> t;
		dij(h, s, d);
		dij(rh, t, rd);
		for (int i = 1; i <= m; i++) {
			if (u[i] == v[i])continue;
			int a = u[i], b = v[i], c = w[i];
			if (d[a] + c + rd[b] == d[t]) {
				add(wh, a, b, 1);
				add(wh, b, a, 0);
			}
		}
		int ans = 0;
		while (bfs()) 
			ans += dinic(s,inf);
		cout << ans << endl;
	}
	system("pause");
	return 0;
}