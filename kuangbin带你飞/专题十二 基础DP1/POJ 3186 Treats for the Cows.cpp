#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[2005][2005], num[2005];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++)
		dp[i][i] = num[i] * n;
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			dp[i][j] = max(dp[i + 1][j] + num[i] * (n - len + 1), dp[i][j - 1] + num[j] * (n - len + 1));
		}
	}
	cout << dp[0][n - 1] << endl;
	system("pause");
	return 0;
}