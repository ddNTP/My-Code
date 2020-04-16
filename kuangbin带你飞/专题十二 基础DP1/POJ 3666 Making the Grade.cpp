#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 2005;
int a[N], b[N];
long long dp[N][N];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		long long t = dp[i - 1][1];
		for (int j = 1; j <= n; j++) {
			t = min(t, dp[i - 1][j]);
			dp[i][j] = t + abs(a[i] - b[j]);
		}
	}
	long long ans = dp[n][1];
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[n][i]);
	memset(dp, 0, sizeof(dp));
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		long long t = dp[i - 1][1];
		for (int j = 1; j <= n; j++) {
			t = min(t, dp[i - 1][j]);
			dp[i][j] = t + abs(a[i] - b[j]);
		}
	}
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[n][i]);
	cout << ans << endl;
	system("pause");
	return 0;
}