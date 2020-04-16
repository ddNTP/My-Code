#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;
struct node {
	int x, y, z;
};
char dun[31][31][31];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int l, r, c;
int sx, sy, sz;
int ex, ey, ez;
int res;
queue<node>q;
int bfs(int x, int y, int z) {
	int lev = 0;
	node u;
	u.x = x;
	u.y = y;
	u.z = z;
	dun[x][y][z] = '#';
	q.push(u);
	while (!q.empty()) {
		int n = q.size();
		lev++;
		for (int i = 0; i < n; i++) {
			node t = q.front();
			q.pop();
			for (int j = 0; j < 6; j++) {
				int tx = t.x + dx[j];
				int ty = t.y + dy[j];
				int tz = t.z + dz[j];
				if (tx >= 0 && tx < l&&ty >= 0 && ty < r&&tz >= 0 && tz < c) {
					if (dun[tx][ty][tz] == '.') {
						u.x = tx;
						u.y = ty;
						u.z = tz;
						dun[tx][ty][tz] = '#';
						q.push(u);

					}
					else if (dun[tx][ty][tz] == 'E') {
						while (!q.empty())q.pop();
						return lev;
					}

				}
			}
		}
	}
	return INT_MAX;

}
int main() {
	cin >> l >> r >> c;
	while (l != 0 && r != 0 && c != 0) {
		res = INT_MAX;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				scanf("%s", dun[i][j]);
				for (int k = 0; k < c; k++)
					if (dun[i][j][k] == 'S') {
						sx = i;
						sy = j;
						sz = k;
					}
					else if (dun[i][j][k] == 'E') {
						ex = i;
						ey = j;
						ez = k;
					}
			}
		}
		res = bfs(sx, sy, sz);
		if (res == INT_MAX)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", res);
		cin >> l >> r >> c;
	}
	system("pause");
	return 0;
}