#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 105;
int fa[N], root[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
struct edge
{
	int u, v, w;
	edge(int x,int y,int z):u(x),v(y),w(z){}
	bool operator<(const edge&a)const {
		return w > a.w;
	}
};
void unio(int x, int y) {
	int f1 = findfa(x);
	int f2 = findfa(y);
	if (f1 != f2)fa[f1] = f2;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		fa[i] = i;
	priority_queue<edge>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int w;
			cin >> w;
			q.push(edge(i, j, w));
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		unio(u-1, v-1);
	}
	for (int i = 0; i < n; i++)
		root[findfa(i)]++;
	int x = 0;
	for (int i = 0; i < n; i++)
		if (root[i])x++;
	int ans = 0, cnt = 0;
	while (!q.empty() && cnt != x - 1) {
		edge e = q.top();
		q.pop();
		int u = e.u, v = e.v, w = e.w;
		int f1 = findfa(u), f2 = findfa(v);
		if (f1 != f2) {
			fa[f1] = f2;
			cnt++;
			ans += w;
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}