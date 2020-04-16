#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 205, M = 2e5 + 5;
struct edge
{
	int next, to;
	double w;
}e[M];
struct Node
{
	int x, y;
}node[N];
int h[N], cnt;
void add(int u, int v, double w) {
	e[++cnt].next = h[u];
	e[cnt].to = v;
	e[cnt].w = w;
	h[u] = cnt;
}
double getdis(int x1, int y1, int x2, int y2,int v) {
	int x = abs(x1 - x2);
	int y = abs(y1 - y2);
	return sqrt(x*x + y * y) / v / 1000 * 60;
}
int vis[N];
double dis[N];
struct tnode
{
	int  v;
	double d;
	tnode(double x,int y):d(x),v(y){}
	bool operator <(const tnode &a)const {
		return d > a.d;
	}
};
void dij() {
	priority_queue<tnode>q;
	fill(dis, dis + N, 1e18);
	dis[0] = 0;
	q.push(tnode(0, 0));
	while (!q.empty()) {
		tnode t = q.top();
		q.pop();
		if (vis[t.v])continue;
		vis[t.v] = 1;
		for (int i = h[t.v]; i; i = e[i].next) {
			int v = e[i].to;
			double w = dis[t.v] + e[i].w;
			if (w < dis[v]) {
				dis[v] = w;
				q.push(tnode(w, v));
			}
		}
	}
}
int main() {
	int id = 1;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	node[0].x = sx;
	node[0].y = sy;
	node[201].x = ex;
	node[201].y = ey;
	add(0, 201, getdis(sx, sy, ex, ey, 10));
	add(201, 0, getdis(sx, sy, ex, ey, 10));
	while (scanf("%d %d", &node[id].x, &node[id].y)!=EOF) {
		add(0, id, getdis(sx, sy, node[id].x, node[id].y, 10));
		add(id, 0, getdis(sx, sy, node[id].x, node[id].y, 10));
		add(201, id, getdis(ex, ey, node[id].x, node[id].y, 10));
		add(id, 201, getdis(ex, ey, node[id].x, node[id].y, 10));
		id++;
		while (scanf("%d %d", &node[id].x, &node[id].y) && node[id].x != -1) {
			add(0, id, getdis(sx, sy, node[id].x, node[id].y, 10));
			add(id, 0, getdis(sx, sy, node[id].x, node[id].y, 10));
			add(201, id, getdis(ex, ey, node[id].x, node[id].y, 10));
			add(id, 201, getdis(ex, ey, node[id].x, node[id].y, 10));
			add(id-1, id, getdis(node[id-1].x, node[id-1].y, node[id].x, node[id].y, 40));
			add(id, id-1, getdis(node[id-1].x, node[id-1].y, node[id].x, node[id].y, 40));
			id++;
		}
	}
	for (int i = 1; i < id; i++)
		for (int j = i + 1; j < id; j++) {
			add(i, j, getdis(node[i].x, node[i].y, node[j].x, node[j].y, 10));
			add(j, i, getdis(node[i].x, node[i].y, node[j].x, node[j].y, 10));
		}
	dij();
	cout << int(dis[201] + 0.5) << endl;
	system("pause");
	return 0;
}