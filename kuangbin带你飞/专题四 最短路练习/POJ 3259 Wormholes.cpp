#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
int N, M, W;
int graph[505][505];
int dis[505];
int vis[505];
int cnt[505];
bool spfa(int s) {
	memset(dis, inf, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	dis[s] = 0;
	queue<int>q;
	q.push(s);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		vis[t] = 0;
		for (int i = 1; i <= N; i++) {
			if (dis[i] > dis[t] + graph[t][i]) {
				dis[i] = dis[t] + graph[t][i];
				if (vis[i])continue;
				q.push(i);
				vis[i] = 1;
				cnt[i]++;
				if (cnt[i] > N)return true;
			}
		}
	}
	return false;
}
int vv[505];
void dfs(int t) {
	for (int i = 1; i <= N; i++) {
		if (!vv[i] && graph[t][i] != inf) {
			vv[i] = 1;
			dfs(i);
		}
	}
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> N >> M >> W;
		memset(graph, inf, sizeof(graph));
		for (int i = 0; i < M; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			if (t3 < graph[t1][t2]) {
				graph[t1][t2] = t3;
				graph[t2][t1] = t3;
			}
		}
		for (int i = 0; i < W; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			if (-t3 < graph[t1][t2])graph[t1][t2] = -t3;
		}
		int i = 1;
		memset(vv, 0, sizeof(vv));
		for (; i <= N; i++) {
			if (vv[i])continue;
			dfs(i);
			if (spfa(i)) {
				printf("YES\n");
				break;
			}
		}
		if (i > N)printf("NO\n");
	}
	system("pause");
	return 0;
}