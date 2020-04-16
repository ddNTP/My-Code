#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define mod 100000
const int inf = 0x3f3f3f3f;
int n, m;
int g[101][101], f[505];
int getf(int i) {
	if (i == 0)return 1;
	else if (i == 1)return 2;
	else {
		int ans = getf(i / 2);
		ans = (ans*ans) % mod;
		if (i % 2 == 1)ans = (2 * ans) % mod;
		return ans;
	}
}
void init() {
	for (int i = 0; i <= 500; i++)
		f[i] = getf(i);
}
int vis[101], dis[101];
bool operator<(vector<int>&a, vector<int>&b) {
	int size = min(a.size(), b.size());
	for (int i = 0; i < size; i++) {
		if (a[i] < b[i])return true;
		else if (a[i] > b[i])return false;
	}
	return a.size() < b.size() ? true : false;
}
bool cmp(int a, int b) {
	return a > b;
}
void dij() {
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	vector<int>d[101];
	vector<int>Inf(500, inf);
	for (int i = 1; i < n; i++)d[i] = Inf;
	dis[0] = 0;
	d[0].push_back(0);
	while (1) {
		int u = -1;
		vector<int>minn = Inf;
		for (int i = 0; i < n; i++) {
			if (!vis[i] && d[i] < minn) {
				u = i;
				minn = d[i];
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		for (int i = 0; i < n; i++) {
			if (!vis[i] && g[u][i] != inf) {
				if (d[u][0] < d[i][0] && g[u][i] < d[i][0]) {
					d[i] = d[u];
					d[i].push_back(g[u][i]);
					sort(d[i].begin(), d[i].end(), cmp);
					dis[i] = (dis[u] + f[g[u][i]]) % mod;
				}
				else if (g[u][i] > d[i][0])continue;
				else {
					vector<int>tmp = d[u];
					tmp.push_back(g[u][i]);
					sort(tmp.begin(), tmp.end(), cmp);
					if (tmp < d[i]) {
						d[i] = tmp;
						dis[i] = (dis[u] + f[g[u][i]]) % mod;
					}
				}
			}
		}
	}
}
int main() {
	init();
	while (cin >> n >> m) {
		memset(g, inf, sizeof(g));
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (g[a][b] == inf)g[a][b] = g[b][a] = i;
		}
		dij();
		for (int i = 1; i < n; i++) {
			if (dis[i] == inf)cout << -1 << endl;
			else cout << dis[i] << endl;
		}
	}
	return 0;
}