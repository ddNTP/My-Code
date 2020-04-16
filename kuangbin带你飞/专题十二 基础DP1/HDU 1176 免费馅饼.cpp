#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5, inf = 0x3f3f3f3f;
int dp[13][N], num[13][N];
int getmax(int i, int j) {
	int t1 = max(dp[i - 1][j - 1], dp[i][j - 1]);
	return max(dp[i + 1][j - 1], t1) + num[i][j];
}
int main() {
	int n;
	while (scanf("%d", &n)) {
		if (n == 0)break;
		int tmax = 0;
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; i++) {
			int t1, t2;
			scanf("%d%d", &t1,&t2);
			num[t1 + 1][t2]++;
			tmax = max(tmax, t2);
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= tmax; i++) {
			for (int j = 0; j <=5&&j<=i; j++) {
				dp[6 - j][i] = getmax(6 - j, i);
				dp[6 + j][i] = getmax(6 + j, i);
			}
		}
		int ans = 0;
		for (int i = 1; i <= 11; i++)
			ans = max(ans, dp[i][tmax]);
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}