#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	int i, j, step;
	node(int x,int y,int z):i(x),j(y),step(z){}
};
int vis1[1005][1005];
char maze[1005][1005];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int R, C;
bool isvalid(int x, int y) {
	if (x < 0 || x >= R || y < 0 || y >= C)return false;
	return true;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> R >> C;
		memset(vis1, 0, sizeof(vis1));
		queue<node>q1, q2;
		getchar();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				scanf("%c", &maze[i][j]);
				if (maze[i][j] == 'J') {
					q1.push(node(i, j, 0));
					vis1[i][j] = 1;
				}
				if (maze[i][j] == 'F') 
					q2.push(node(i, j, 0));
			}
			getchar();
		}
		bool flag = false;
		while (!q1.empty()) {
			int n2 = q2.size();
			for (int j = 0; j < n2; j++) {
				node t = q2.front();
				q2.pop();
				for (int k = 0; k < 4; k++) {
					int tx = t.i + dx[k];
					int ty = t.j + dy[k];
					if (isvalid(tx, ty)&&maze[tx][ty]!='#'&&maze[tx][ty]!='F') {
						q2.push(node(tx, ty, t.step + 1));
						maze[tx][ty] = 'F';
					}
				}
			}
			int n1 = q1.size();
			for (int j = 0; j < n1; j++) {
				node t = q1.front();
				q1.pop();
				if (t.i == 0 || t.i == R - 1 || t.j == 0 || t.j == C - 1) {
					printf("%d\n", t.step + 1);
					flag = true;
					break;
				}
				for (int k = 0; k < 4; k++) {
					int tx = t.i + dx[k];
					int ty = t.j + dy[k];
					
					if (!vis1[tx][ty] && maze[tx][ty] == '.') {
						vis1[tx][ty] = 1;
						q1.push(node(tx, ty, t.step + 1));
					}
				}
			}
			if (flag)break;
		}
		if (!flag)printf("IMPOSSIBLE\n");
	}
	system("pause");
	return 0;
}