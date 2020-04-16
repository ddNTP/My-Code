#include<map>
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
double graph[35][35];
int n;
double dis[35];
int cnt[35];
int vis[35];
bool spfa(int s) {
	mm(dis, 0);
	mm(cnt, 0);
	mm(vis, 0);
	dis[s] = 1;
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		vis[t] = 0;
		for (int i = 1; i <= n; i++) {
			double val = dis[t] * graph[t][i];
			if (val-dis[i]>1e-8) {
				dis[i] = val;
				if (vis[i])continue;
				q.push(i);
				vis[i] = 1;
				if (++cnt[i] > n)return true;
			}
		}
	}
	return false;
}
int dvis[35];
void dfs(int t) {
	for (int i = 1; i <= n; i++) {
		if (!dvis[i] && graph[t][i] != 0) {
			dvis[i] = 1;
			dfs(i);
		}
	}
}
int main() {
	cin >> n;
	int id = 1;
	while (n != 0) {
		mm(dvis, 0);
		mm(graph, 0);
		map<string, int>mp;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			mp[s] = i;
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			string t1, t2;
			double t3;
			cin >> t1 >> t3 >> t2;
			graph[mp[t1]][mp[t2]] = max(graph[mp[t1]][mp[t2]], t3);
		}
		int i = 1;
		for (; i <= n; i++) {
			if (dvis[i])continue;
			dfs(i);
			if (spfa(i)) {
				printf("Case %d: Yes\n", id++);
				break;
			}
		}
		if (i > n)printf("Case %d: No\n", id++);
		cin >> n;
	}
	system("pause");
	return 0;
}