#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char grid[105][105];
int vis[105][105];
int m, n;
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,1,-1,1,1,-1,-1 };
void dfs(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx>=0&&tx<m&&ty>=0&&ty<n&&!vis[tx][ty] && grid[tx][ty] == '@') {
			vis[tx][ty] = 1;
			dfs(tx, ty);
		}
	}
}
int main() {
	cin >> m >> n;
	while (m != 0) {
		int res = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i++) 
			scanf("%s", grid[i]);
		for (int i = 0; i < m; i++) {
			for(int j=0;j<n;j++)
				if (!vis[i][j] && grid[i][j] == '@') {
					vis[i][j] = 1;
					dfs(i, j);
					res++;
				}
		}
		cout << res << endl;
		cin >> m >> n;
	}
	system("pause");
	return 0;
}