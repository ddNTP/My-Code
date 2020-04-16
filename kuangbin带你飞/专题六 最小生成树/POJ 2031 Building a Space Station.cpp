#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 105;
struct Node
{
	double x, y, z, r;
}node[N];
struct edge
{
	int u, v;
	double w;
	edge(int x,int y,double z):u(x),v(y),w(z){}
	bool operator<(const edge&a)const {
		return w > a.w;
	}
};
int fa[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
double getdis(int u, int v) {
	double x = node[u].x - node[v].x;
	double y = node[u].y - node[v].y;
	double z = node[u].z - node[v].z;
	return max(0.0, pow(x*x + y * y + z * z, 0.5) - node[u].r - node[v].r);
}
int main() {
	int n;
	while (cin >> n) {
		if (n == 0)break;
		for (int i = 0; i < n; i++) {
			cin >> node[i].x >> node[i].y >> node[i].z >> node[i].r;
			fa[i] = i;
		}
		priority_queue<edge>q;
		for (int i = 0; i < n; i++) 
			for (int j = i + 1; j < n; j++) 
				q.push(edge(i, j, getdis(i, j)));
		double ans = 0;
		int cnt = 0;
		while (!q.empty() && cnt != n - 1) {
			edge e = q.top();
			q.pop();
			int u = e.u, v = e.v;
			double w = e.w;
			int f1 = findfa(u), f2 = findfa(v);
			if (f1 != f2) {
				fa[f1] = f2;
				cnt++;
				ans += w;
			}
		}
		printf("%.3f\n", ans);
	}
	system("pause");
	return 0;
}