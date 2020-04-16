#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
const int N = 105, inf = 0x3f3f3f3f;
const double inf2 = 1e8;
double g[N][N], d[N];
int vis[N], n;
struct Node
{
	int x, y;
}node[N];
double getdis(int i, int j) {
	int x = node[i].x - node[j].x;
	int y = node[i].y - node[j].y;
	return sqrt(x*x + y * y);
}
void prim() {
	mm(vis, 0);
	fill(d, d + N, inf2);
	d[0] = 0;
	double ans = 0;
	int i;
	for (i = 0; i < n; i++) {
		int u = -1;
		double minn = inf2;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && d[j] < minn) {
				u = j;
				minn = d[j];
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		ans += d[u];
		for (int j = 0; j < n; j++) 
			if (!vis[j])d[j] = min(d[j], g[u][j]);
	}
	if (i != n)printf("oh!\n");
	else printf("%.1f\n", ans * 100);

}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d%d", &node[i].x, &node[i].y);
		fill(g[0], g[0] + N * N, inf2);
		for(int i=0;i<n;i++)
			for (int j = i + 1; j < n; j++) {
				double w = getdis(i, j);
				if (w < 10 || w>1000)continue;
				g[i][j] = g[j][i] = w;
			}
		prim();
	}
	system("pause");
	return 0;
}