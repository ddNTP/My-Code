#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
const int N = 800;
struct Node
{
	int x, y;
}node[N];
int g[N][N];
double getdis(int u, int v) {
	int x = node[u].x - node[v].x;
	int y = node[u].y - node[v].y;
	return sqrt(x*x + y * y);
}
struct edge
{
	int u, v;
	double w;
	edge(int x,int y,double z):u(x),v(y),w(z){}
	bool operator<(const edge&a)const {
		return w > a.w;
	}
};
int fa[N], root[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= n; i++)
		cin >> node[i].x >> node[i].y;
	priority_queue<edge>q;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			q.push(edge(i, j, getdis(i, j)));
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		int f1 = findfa(u), f2 = findfa(v);
		fa[f1] = f2;
	}
	for (int i = 1; i <= n; i++)
		root[findfa(i)]++;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (root[i])cnt++;
	if (cnt == 1)printf("\n");
	while (!q.empty() && cnt != 1) {
		edge e = q.top();
		q.pop();
		int u = e.u, v = e.v;
		double w = e.w;
		int f1 = findfa(u), f2 = findfa(v);
		if (f1 != f2) {
			cnt--;
			fa[f1] = f2;
			printf("%d %d\n", e.u, e.v);
		}
	}
	system("pause");
	return 0;
}