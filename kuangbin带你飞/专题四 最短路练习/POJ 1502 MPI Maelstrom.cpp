#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int n;
int graph[105][105];
const int inf = 0x3f3f3f3f;
int vis[105];
int dis[105];
void dij() {
	memset(dis, inf, sizeof(dis));
	dis[1] = 0;
	while (1) {
		int u = -1, minn = inf;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && dis[i] < minn) {
				u = i;
				minn = dis[i];
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && dis[i] > dis[u] + graph[u][i])
				dis[i] = dis[u] + graph[u][i];
		}
	}
}
int getnum(string s) {
	int num = 0;
	for (int i = 0; i < s.size(); i++) 
		num = num * 10 + s[i] - '0';
	return num;
}
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			string t;
			cin >> t;
			if (t[0] == 'x')
				graph[i][j] = graph[j][i] = inf;
			else
				graph[i][j] = graph[j][i] = getnum(t);
		}
	}
	dij();
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (res < dis[i])
			res = dis[i];
	cout << res << endl;
	system("pause");
	return 0;
}