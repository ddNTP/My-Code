#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N = 55;
int fa[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));;
}
struct edge {
	int u, v, w;
	edge(int x,int y,int z):u(x),v(y),w(z){}
	bool operator<(const edge&a)const {
		return w > a.w;
	}
};
int main() {
	int n, m;
	while (cin >> n) {
		if (n == 0)break;
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		cin >> m;
		priority_queue<edge>q;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			q.push(edge(u, v, w));
		}
		int ans = 0, cnt = 0;
		while (!q.empty() && cnt != n - 1) {
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
	}
	system("pause");
	return 0;
}