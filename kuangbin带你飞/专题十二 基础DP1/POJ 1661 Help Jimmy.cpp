#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n, x, y, maxn;
const int inf = 0x3f3f3f3f;
struct Node
{
	int x1, x2, h;
	bool operator<(const Node &a)const {
		return h < a.h;
	}
}node[1005];
int dp[1005][2];
void left(int x) {
	if (node[x].h - node[0].h <= maxn) {
		int i = 1;
		for (; i < x; i++) {
			if (node[i].x1 <= node[x].x1&&node[i].x2 >= node[x].x1)
				break;
		}
		if (i == x) {
			dp[x][0] = node[x].h - node[0].h;
			return;
		}
	}
	int i = x - 1;
	while(i>=1&&node[x].h-node[i].h<=maxn){
		if (node[x].x1 >= node[i].x1&&node[x].x1 <= node[i].x2) {
			dp[x][0] = min(dp[x][0], min(dp[i][0] + node[x].x1 - node[i].x1, dp[i][1] + node[i].x2 - node[x].x1) + node[x].h - node[i].h);
			break;
		}
		i--;
	}
}
void right(int x) {
	if (node[x].h - node[0].h <= maxn) {
		int i = 1;
		for (; i < x; i++) {
			if (node[i].x1 <= node[x].x2&&node[i].x2 >= node[x].x2)
				break;
		}
		if (i == x) {
			dp[x][1] = node[x].h - node[0].h;
			return;
		}
	}
	int i = x - 1;
	while (i >= 1 && node[x].h - node[i].h <= maxn) {
		if (node[x].x2 >= node[i].x1&&node[x].x2 <= node[i].x2) {
			dp[x][1] = min(dp[x][1], min(dp[i][0] + node[x].x2 - node[i].x1, dp[i][1] + node[i].x2 - node[x].x2) + node[x].h - node[i].h);
			break;
		}
		i--;
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> x >> y >> maxn;
		node[0].x1 = node[0].x2 = x;
		node[0].h = y;
		node[1].x1 = -20000, node[1].x2 = 20000, node[1].h = 0;
		for (int i = 2; i < n+2; i++)
			cin >> node[i].x1 >> node[i].x2 >> node[i].h;
		memset(dp, inf, sizeof(dp));
		dp[0][0] = dp[0][1] = 0;
		sort(node, node + n + 2);
		for (int i = 1; i < n + 2; i++) {
			left(i);
			right(i);
		}
		cout << dp[n + 1][0] << endl;
	}
	system("pause");
	return 0;
}