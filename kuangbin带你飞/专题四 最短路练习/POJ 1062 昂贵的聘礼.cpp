#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 105, M = 2e5 + 5;
struct edge
{
	int next, to, w;
}e[M];
const int inf = 0x3f3f3f3f;
int head[N], cnt, k, n, L[N], dis[N], vis[N];
void add(int u, int v, int w) {
	e[++cnt].next = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	head[u] = cnt;
}
struct node {
	int d, v;
	node(int x,int y):d(x),v(y){}
	bool operator <(const node &a)const {
		return d > a.d;
	}
};
void dij(int l, int r) {
	memset(dis, inf, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[0] = 0;
	priority_queue<node>q;
	q.push(node(0, 0));
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (vis[t.v])continue;
		vis[t.v] = 1;
		for (int i = head[t.v]; i; i = e[i].next) {
			int v = e[i].to;
			int val = dis[t.v] + e[i].w;
			if (L[v] > r || L[v] < l)continue;
			if (val < dis[v]) {
				dis[v] = val;
				q.push(node(val, v));
			}
		}
	}
}
int main() {
	cin >> k >> n;
	for (int i = 1; i <= n; i++) {
		int w, x;
		scanf("%d %d %d", &w, &L[i], &x);
		add(0, i, w);
		while (x--) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			add(t1, i, t2);
		}
	}
	int res = inf;
	for (int i = L[1] - k; i <= L[1]; i++) {
		dij(i, i + k);
		res = min(res, dis[1]);
	}
	cout << res << endl;
	system("pause");
	return 0;
}