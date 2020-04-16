#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 150005;
struct edge
{
	int next, to, w;
}e[maxn];
int N, M;
int h[maxn], cnt;
void add(int u, int v, int w) {
	e[++cnt].next = h[u];
	e[cnt].to = v;
	e[cnt].w = w;
	h[u] = cnt;
}
struct node
{
	int v, d;
	node(int x, int y) :v(x), d(y) {}
	bool operator <(const node &a)const {
		return d > a.d;
	}
};
int vis[maxn], d[maxn];
const int inf = 0x3f3f3f3f;
void dij(int s) {
	memset(vis, 0, sizeof(vis));
	memset(d, inf, sizeof(d));
	priority_queue<node>q;
	d[s] = 0;
	q.push(node(s, 0));
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (vis[t.v])continue;
		vis[t.v] = 1;
		for (int i = h[t.v]; i; i = e[i].next) {
			int val = d[t.v] + e[i].w;
			if (val < d[e[i].to]) {
				d[e[i].to] = val;
				q.push(node(e[i].to, val));
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		add(t1, t2, t3);
	}
	dij(1);
	cout << d[N] << endl;
	system("pause");
	return 0;
}