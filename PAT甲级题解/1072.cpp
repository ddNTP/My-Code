#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	int index;
	int dis;
	node(int x, int y) :index(x), dis(y) {

	}
};
struct node1
{
	double min;
	double ave;
	int index;
	node1(int y, double m, double n) : index(y), min(m), ave(n) {

	}
};
int n, m, k, ds;
vector<node>v[1020];
int getID(string s) {
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i]!='G') {
			res = res * 10 + s[i] - '0';
		}
	}
	if (s[0] == 'G')res += n;
	return res;
}
bool vis[1020];
int d[1020];
int inf = 0x3fffffff;
void dijkstra(int index) {
	fill(vis, vis + 1020, false);
	fill(d, d + 1020, inf);
	d[index] = 0;
	for (int i = 0; i < n + m; i++) {
		int u = -1, min = inf;
		for (int j = 1; j <= n + m; j++) {
			if (!vis[j]&&d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int j = 0; j <v[u].size(); j++) {
			node t = v[u][j];
			if (!vis[t.index]) {
				if (d[u] + t.dis < d[t.index]) {
					d[t.index] = d[u] + t.dis;
				}
			}
		}
	}
}
bool cmp1(node1 a, node1 b) {
	if (a.min != b.min)return a.min > b.min;
	else if (a.min == b.min&&a.ave != b.ave)return a.ave < b.ave;
	else return a.index < b.index;
}
int main() {
	cin >> n >> m >> k >> ds;
	for (int i = 0; i < k; i++) {
		string s1, s2;
		int t;
		cin >> s1 >> s2 >> t;
		int t1, t2;
		t1 = getID(s1);
		t2 = getID(s2);
		node a(t1, t);
		node b(t2, t);
		v[t1].push_back(b);
		v[t2].push_back(a);
	}
	vector<node1>ans;
	for (int i = n + 1; i <= n + m; i++) {
		dijkstra(i);
		double ave = 0;
		int index = i - n;
		double min = inf;
		bool flag = false;
		for (int j = 1; j <= n; j++) {
			if (d[j] > ds) {
				flag = true;
				break;
			}
			ave += 1.0*d[j] / n;
			if (min > d[j])min = d[j];
		}
		if (flag)continue;
		node1 a(index, min, ave);
		ans.push_back(a);
	}
	if (ans.size() == 0) {
		printf("No Solution");
		system("pause");
		return 0;
	}
	sort(ans.begin(), ans.end(), cmp1);
	printf("G%d\n%.1f %.1f", ans[0].index, ans[0].min, ans[0].ave);
	system("pause");
	return 0;
}