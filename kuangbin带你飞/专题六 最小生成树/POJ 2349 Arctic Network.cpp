#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 505, inf = 0x3f3f3f3f;

int fa[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
struct Node
{
	int x, y;
}node[N];
double getdis(int u, int v) {
	int x = node[u].x - node[v].x;
	int y = node[u].y - node[v].y;
	return pow(x*x + y * y, 0.5);
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
int main() {
	int T;
	cin >> T;;
	while (T--) {
		int s, n;
		cin >> s >> n;
		for (int i = 0; i < n; i++)
			fa[i] = i;
		for (int i = 0; i < n; i++) 
			cin >> node[i].x >> node[i].y;
		priority_queue<edge>q;
		
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				q.push(edge(i, j, getdis(i, j)));
		double ans = 0;
		int cnt = 0;
		while (!q.empty() && cnt != n - s) {
			edge e = q.top();
			q.pop();
			int u = e.u, v = e.v;
			double w = e.w;
			int f1 = findfa(u), f2 = findfa(v);
			if (f1 != f2) {
				fa[f1] = f2;
				cnt++;
				ans = max(ans, w);
			}
		}
		printf("%.2f\n", ans);
	}
	system("pause");
	return 0;
}