#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
typedef long long ll;
int n, Q;
const int M = 2e6 + 5;
const int X = 1e6 + 5;
const int inf =0x3f3f3f3f;
struct edge
{
	int to, next, w;
}e[M];
struct node {
	int v;
	ll d;
	node (int x,ll y):v(x),d(y){}
	bool operator <(const node  &a)const {
		return	d > a.d;
	}
};

int cnt, h[X], rh[X];
ll d[X], rd[X];
void add(int hd[], int u, int v, int w) {
	e[++cnt].next = hd[u];
	e[cnt].to = v;
	e[cnt].w = w;
	hd[u] = cnt;
}
int vis[X];
void dij(int hd[],ll dis[]) {
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(d));
	priority_queue<node>q;
	dis[1] = 0;
	q.push(node(1, 0));
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (vis[t.v])continue;
		vis[t.v] = 1;
		for (int i = hd[t.v]; i; i = e[i].next) {
			ll t1 = dis[t.v] + e[i].w;
			if (t1 < dis[e[i].to]) {
				dis[e[i].to] = t1;
				q.push(node(e[i].to, t1));
			}
		}
	}
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		mm(h, 0);
		mm(rh, 0);
		cin >> n >> Q;
		for (int i = 0; i < Q; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			add(h, t1, t2, t3);
			add(rh, t2, t1, t3);
		}
		dij(h, d);
		dij(rh, rd);
		ll res = 0;
		for (int i = 1; i <= n; i++)
			res += d[i] + rd[i];
		cout << res << endl;
	}
	system("pause");
	return 0;
}