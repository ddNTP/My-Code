#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 105;
int dp[N][N], a[N][N];
int n, m;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int dfs(int x, int y) {
	if (dp[x][y] != -1)return dp[x][y];
	dp[x][y] = a[x][y];
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			int xx = x + i * dx[j];
			int yy = y + i * dy[j];
			if (xx >= 0 && xx < n&&yy >= 0 && yy < n&&a[xx][yy]>a[x][y]) {
				dp[x][y] = max(dp[x][y], dfs(xx, yy) + a[x][y]);
			}
		}
	}
	return dp[x][y];
}
int main() {

	while (cin >> n >> m) {
		if (n == -1 && m == -1)break;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		cout << dfs(0, 0) << endl;
	}
	system("pause");
	return 0;
}