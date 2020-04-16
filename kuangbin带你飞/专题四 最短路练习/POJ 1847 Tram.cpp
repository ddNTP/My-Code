#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 105, M = 2e5 + 5, inf = 0x3f3f3f3f;
int n, a, b;

struct edge {
	int next, to, w;
}e[M];
int head[N], cnt;
void add(int u, int v, int w) {
	e[++cnt].next = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	head[u] = cnt;
}
int dis[N], vis[N];
struct node {
	int d, v;
	node(int x,int y):d(x),v(y){}
	bool operator <(const node &a)const {
		return d > a.d;
	}
};
void dij() {
	memset(dis, inf, sizeof(dis));
	dis[a] = 0;
	priority_queue<node>q;
	q.push(node(0, a));
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
int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int t;
			cin >> t;
			if (j == 0)add(i, t, 0);
			else add(i, t, 1);
		}
	}
	dij();
	if (dis[b] != inf)
		cout << dis[b] << endl;
	else
		cout << -1 << endl;
	system("pause");
	return 0;
}