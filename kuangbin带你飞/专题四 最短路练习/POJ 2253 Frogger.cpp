#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
double dis[205][205];
const double inf = 0x3f3f3f3f;
struct node
{
	int x, y;
	node():x(0),y(0){}
	node(int i,int j):x(i),y(j){}
};
node all[205];
int n;
void getdis() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = dis[j][i] = sqrt(pow(abs(all[i].x - all[j].x), 2) + pow(all[i].y - all[j].y, 2));
		}
	}
}
double d[205];
int vis[205];
void dij() {
	memset(vis, 0, sizeof(vis));
	fill(d, d + 205, inf);
	d[0] = 0;
	while (1) {
		int u = -1, minn = inf;
		for (int i = 0; i < n; i++) {
			if (!vis[i]&&d[i] < minn) {
				minn = d[i];
				u = i;
			}
		}
		if (u == -1)break;
		vis[u] = 1;
		for (int i = 0; i < n; i++)
			d[i] = min(d[i], max(d[u], dis[u][i]));
	}
}
int main() {
	int id = 1;
	cin >> n;
	while (n != 0) {
		memset(dis, inf, sizeof(dis));
		for (int i = 0; i < n; i++) 
			scanf("%d %d", &all[i].x, &all[i].y);
		getdis();
		dij();
		printf("Scenario #%d\n", id++);
		printf("Frog Distance = %.3f\n\n", d[1]);
		cin >> n;
	}
	system("pause");
	return 0;
}