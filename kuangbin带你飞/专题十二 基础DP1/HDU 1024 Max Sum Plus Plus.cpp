#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 1e6 + 5, inf = 0x3f3f3f3f;
int num[N], dp[N], pre[N];
int main() {
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF) {
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		memset(dp, 0, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		int maxn;
		for (int i = 1; i <= m; i++) {
			maxn = -inf;
			for (int j = i; j <= n; j++) {
				dp[j] = max(dp[j - 1] + num[j], pre[j - 1] + num[j]);
				pre[j - 1] = maxn;
				maxn = max(dp[j], maxn);
			}
		}
		printf("%d\n", maxn);
	}
	system("pause");
	return 0;
}