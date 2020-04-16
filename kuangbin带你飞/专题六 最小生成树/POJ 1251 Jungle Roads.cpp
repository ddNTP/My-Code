#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 30;
int fa[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
struct edge
{
	int u, v, w;
	edge(int x,int y,int z):u(x),v(y),w(z){}
	bool operator<(const edge &a)const {
		return w > a.w;
	}
};
int main() {
	int n;
	while (cin >> n) {
		if (n == 0)break;
		char c;
		for (int i = 0; i < n; i++)
			fa[i] = i;
		priority_queue<edge>q;
		int k;
		for (int i = 0; i < n-1; i++) {
			cin >> c >> k;
			char v;
			int w;
			for (int j = 0; j < k; j++) {
				cin >> v >> w;
				q.push(edge(c - 'A', v - 'A', w));
			}
		}
		int cnt = 0, ans = 0;
		while (!q.empty() && cnt != n - 1) {
			edge e = q.top();
			q.pop();
			int u = e.u, v = e.v, w = e.w;
			int f1 = findfa(u), f2 = findfa(v);
			if (f1 != f2) {
				fa[f1] = f2;
				ans += w;
				cnt++;
			}
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}
