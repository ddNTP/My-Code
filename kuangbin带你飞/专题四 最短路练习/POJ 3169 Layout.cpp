#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
const int N = 1005, M = 5e4 + 5, inf = 0x3f3f3f3f;
struct edge
{
	int next, to, w;
}e[M];
int h[N], cnt, n, ml, md;
void add(int u, int v, int w) {
	e[++cnt].next = h[u];
	e[cnt].to = v;
	e[cnt].w = w;
	h[u] = cnt;
}

int dis[N], vis[N], ct[N];
bool spfa() {
	queue<int>q;
	mm(dis, inf);
	dis[1] = 0;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		vis[t] = 0;
		for (int i = h[t]; i; i = e[i].next) {
			int v = e[i].to;
			int val = dis[t] + e[i].w;
			if (val < dis[v]) {
				dis[v] = val;
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
					if (++ct[v] > N)return true;
				}
			}
		}
	}
	return false;
}
int main() {
	cin >> n >> ml >> md;
	for (int i = 0; i < ml; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		int a = max(t1, t2), b = min(t1, t2);
		add(b, a, t3);
	}
	for (int i = 0; i < md; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		int a = max(t1, t2), b = min(t1, t2);
		add(a, b, -t3);
	}
	if (spfa())cout << -1 << endl;
	else {
		cout << (dis[n] == inf ? -2 : dis[n]) << endl;
	}
	system("pause");
	return 0;
}