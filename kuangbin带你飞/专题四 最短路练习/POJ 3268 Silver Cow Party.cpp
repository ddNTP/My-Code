#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int, int> P;
int N, M, X;
int dis[1005][1005];
const int inf = 0x3f3f3f3f;
vector<P>v[1005];

void dij(int s) {
	priority_queue<P, vector<P>, greater<P>>q;
	dis[s][s] = 0;
	q.push(P(0, s));
	while (!q.empty()) {
		P cur = q.top();
		q.pop();
		if (cur.first > dis[s][cur.second])continue;
		int to = cur.second;
		for (int i = 0; i < v[to].size(); i++) {
			P t = v[to][i];
			if (dis[s][t.second] > dis[s][to] + t.first) {
				dis[s][t.second] = dis[s][to] + t.first;
				q.push(P(dis[s][t.second], t.second));
			}
		}
	}
}
int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		v[t1].push_back(P(t3, t2));
	}
	memset(dis, inf, sizeof(dis));
	for (int i = 1; i <= N; i++)
		dij(i);
	int res = 0;
	for (int i = 1; i <= N; i++)
		res = max(res, dis[i][X] + dis[X][i]);
	cout << res << endl;
	system("pause");
	return 0;
}