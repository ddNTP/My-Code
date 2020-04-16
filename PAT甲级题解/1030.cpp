#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int v, dis, cost;
	node() {
		v = 0;
		dis = 0;
		cost = 0;
	}
	node(int x, int y, int z) :v(x), dis(y), cost(z) {

	}
};
vector<node>v[510];
int n, m, s, d;
int dis[510], cost[510];
node pre[510];
const int inf = 0x3fffffff;
bool vis[510];
void dijkstra(int index) {
	fill(dis, dis + 510, inf);
	dis[index] = 0;
	cost[index] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, min = inf;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && min > dis[j]) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int j = 0; j < v[u].size(); j++) {
			node t = v[u][j];
			if (!vis[t.v]) {
				if (dis[u] + t.dis < dis[t.v]) {
					dis[t.v] = dis[u] + t.dis;
					cost[t.v] = cost[u] + t.cost;
					node a(u, t.dis, t.cost);
					pre[t.v] = a;
				}
				else if (dis[u] + t.dis == dis[t.v]) {
					if (cost[u] + t.cost < cost[t.v]) {
						node a(u, t.dis, t.cost);
						pre[t.v] = a;
						cost[t.v] = cost[u] + t.cost;
					}
				}
			}
		}
	}
}
vector<int>ans;
int totcost = 0, totdis = 0;
void dfs(int index) {
	if (index == s) {
		ans.push_back(s);
		return;
	}
	dfs(pre[index].v);
	ans.push_back(index);
	totcost += pre[index].cost;
	totdis += pre[index].dis;
}
int main() {

	cin >> n >> m >> s >> d;
	for (int i = 0; i < m; i++) {
		int t1, t2, t3, t4;
		cin >> t1 >> t2 >> t3 >> t4;
		node a(t1, t3, t4);
		node b(t2, t3, t4);
		v[t1].push_back(b);
		v[t2].push_back(a);
	}

	dijkstra(s);
	dfs(d);
	for (int i = 0; i < ans.size(); i++) 
		printf("%d ", ans[i]);
	printf("%d ", totdis);
	printf("%d", totcost);
	system("pause");
	return 0;
}