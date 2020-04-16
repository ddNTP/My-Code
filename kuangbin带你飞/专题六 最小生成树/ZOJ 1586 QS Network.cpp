#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1005;
int fa[N], w[N];
struct edge
{
	int u, v, w;
	edge(int x, int y, int z) :u(x), v(y), w(z) {}
	bool operator<(const edge &a)const {
		return w > a.w;
	}
};
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> w[i];
		for (int i = 0; i < n; i++)
			fa[i] = i;
		priority_queue<edge>q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;
				q.push(edge(i, j, x + w[i] + w[j]));
			}
		}
		int ans = 0, cnt = 0;
		while (!q.empty() && cnt != n - 1) {
			edge e = q.top();
			q.pop();
			int x = e.u, y = e.v, z = e.w;
			int f1 = findfa(x), f2 = findfa(y);
			if (f1 != f2) {
				ans += z;
				cnt++;
				fa[f1] = f2;
			}
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}