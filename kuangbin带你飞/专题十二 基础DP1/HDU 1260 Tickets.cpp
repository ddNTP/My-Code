#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 2005, inf = 0x3f3f3f3f;
int w[N], tg[N], dp[N];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		for (int i = 2; i <= n; i++)
			scanf("%d", &tg[i]);
		dp[0] = 0;
		dp[1] = w[1];
		for (int i = 2; i <= n; i++)
			dp[i] = min(dp[i - 1] + w[i], dp[i - 2] + tg[i]);
		int hh = dp[n] / 3600;
		dp[n] %= 3600;
		int mm = dp[n] / 60;
		dp[n] %= 60;
		printf("%02d:%02d:%02d am\n", hh + 8, mm, dp[n]);
	}
	system("pause");
	return 0;
}