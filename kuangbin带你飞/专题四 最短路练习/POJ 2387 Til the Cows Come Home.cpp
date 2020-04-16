#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int T, N;
const int inf = 0x3f3f3f3f;
int map[1005][1005];
int vis[1005];
int dis[1005];
void dij() {
	memset(dis, inf, sizeof(dis));
	
	dis[N] = 0;
	while (1) {
		int u = -1, minn = inf;
		for (int i = 1; i <= N; i++) {
			if (!vis[i]&&dis[i] < minn) {
				u = i;
				minn = dis[i];
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		for (int i = 1; i <= N; i++) {
			if (dis[i] > dis[u] + map[u][i])
				dis[i] = dis[u] + map[u][i];
		}
	}
}
int main() {
	cin >> T >> N;
	memset(map, inf, sizeof(map));
	for (int i = 0; i < T; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (map[t1][t2] > t3) {
			map[t1][t2] = t3;
			map[t2][t1] = t3;
		}
	}
	dij();
	cout << dis[1] << endl;
	system("pause");
	return 0;
}