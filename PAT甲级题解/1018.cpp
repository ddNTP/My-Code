#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
struct node
{
	int v, tim;
	node(int x, int y) :v(x), tim(y) {

	}
};
int c[510];
int cm, n, sp, m;
vector<node>v[510];
int d[510];
vector<int> pre[510];
bool vis[510];
int inf = 0x3fffffff;

void dijstrala(int s) {
	fill(d, d + 510, inf);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, min = inf;
		for (int j = 0; j < n; j++) {
			if (d[j] < min&&!vis[j]) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int j = 0; j < v[u].size(); j++) {
			node t = v[u][j];
			if (!vis[t.v]) {
				if (d[u] + t.tim < d[t.v]) {
					pre[t.v].clear();
					pre[t.v].push_back(u);
					d[t.v] = d[u] + t.tim;
				}
				else if (d[u] + t.tim == d[t.v]) {
					pre[t.v].push_back(u);
				}
			}
		}
	}
}
vector<int>tmp, ans;
int total = inf;
int totalt = inf;
int tt = inf;
int ttt = inf;
void dfs(int index,int tot) {
	if (index == 0) {
		tmp.push_back(0);
		int t = 0;
		int totall = 0;
		for (int i = tmp.size() - 2; i > 0; i--) {
			t += (cm / 2 - c[tmp[i]]);
			if (totall < t)totall = t;
		}
		totall = max(totall, tot);
		if (tt>totall ) {
			ans = tmp;
			total = tot;
			totalt = totall;
			tt = max(total, totalt);
			if (total >= totalt)ttt = 0;
			else ttt = -total + totalt;
		}
		else if (tt == totall && ttt > (-tot + totall)) {
			ans = tmp;
			total = tot;
			totalt = totall;
			tt = max(total, totalt);
			if (total >= totalt)ttt = 0;
			else ttt = -total + totalt;
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(index);
	tot = tot + (cm / 2 - c[index]);
	for (int i = 0; i < pre[index].size(); i++) {
		dfs(pre[index][i], tot);
	}
	tmp.pop_back();
}
int main() {
	cin >> cm >> n >> sp >> m;
	for (int i = 1; i <= n; i++) 
		cin >> c[i];
	for (int i = 0; i < m; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		node a(t1, t3);
		node b(t2, t3);
		v[t1].push_back(b);
		v[t2].push_back(a);
	}
	dijstrala(0);
	dfs(sp,0);
	if (total >= totalt)printf("%d ", total);
	else printf("%d ", totalt);
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d", ans[i]);
		if (i != 0)printf("->");
	}
	if (total >= totalt)printf(" 0");
	else printf(" %d", -total + totalt);
	system("pause");
	return 0;
}