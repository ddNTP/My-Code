#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#define maxn 205
using namespace std;
int m, n;
const int inf = 0x3f3f3f3f;
char map[maxn][maxn];
int vis1[maxn][maxn];
int vis2[maxn][maxn];
int tim1[maxn][maxn];
int tim2[maxn][maxn];
int Yi, Yj, Mi, Mj;
struct node
{
	int x, y, step;
	node(int i,int j,int st):x(i),y(j),step(st){}
};
vector<node>kfc;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs() {
	memset(vis1, 0, sizeof(vis1));
	memset(vis2, 0, sizeof(vis2));
	memset(tim1, inf, sizeof(tim1));
	memset(tim2, inf, sizeof(tim2));
	queue<node>q1, q2;
	q1.push(node(Yi, Yj, 0));
	q2.push(node(Mi, Mj, 0));
	vis1[Yi][Yj] = 1;
	vis2[Mi][Mj] = 1;
	while (!q1.empty() || !q2.empty()) {
		int n1 = q1.size();
		for (int k = 0; k < n1; k++) {
			node t1 = q1.front();
			q1.pop();
			for (int i = 0; i < 4; i++) {
				node tt = t1;
				tt.step += 11;
				tt.x += dx[i];
				tt.y += dy[i];
				if (tt.x >= 0 && tt.x < m&&tt.y >= 0 && tt.y < n && !vis1[tt.x][tt.y] && map[tt.x][tt.y] != '#') {
					q1.push(tt);
					tim1[tt.x][tt.y] = tt.step;
					vis1[tt.x][tt.y] = 1;
				}
			}
		}
		int n2 = q2.size();
		for (int k = 0; k < n2; k++) {
			node t2 = q2.front();
			q2.pop();
			for (int i = 0; i < 4; i++) {
				node tt = t2;
				tt.step += 11;
				tt.x += dx[i];
				tt.y += dy[i];
				if (tt.x >= 0 && tt.x < m&&tt.y >= 0 && tt.y < n && !vis2[tt.x][tt.y] && map[tt.x][tt.y] != '#') {
					q2.push(tt);
					vis2[tt.x][tt.y] = 1;
					tim2[tt.x][tt.y] = tt.step;
				}
			}
		}
	}
}
int main() {
	while (scanf("%d %d", &m, &n) != EOF) {
		kfc.clear();
		for (int i=0; i < m; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < n; j++)
				if (map[i][j] == 'Y') {
					Yi = i;
					Yj = j;
				}
				else if (map[i][j] == 'M') {
					Mi = i;
					Mj = j;
				}
		}
		bfs();
		int res = inf;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == '@') {
					res = min(res, tim1[i][j] + tim2[i][j]);
				}
			}
		}
		cout << res << endl;
	}
	system("pause");
	return 0;
}