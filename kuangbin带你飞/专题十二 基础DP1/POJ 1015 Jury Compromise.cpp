#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[21][805], p[205], s[205];
vector<int>path[21][805];
int main() {
	int n, m;
	int cas = 1;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)break;
		for (int i = 0; i < n; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			p[i] = t1 + t2;
			s[i] = t1 - t2;
		}
		memset(dp, -1, sizeof(dp));
		int base = 20 * m;
		dp[0][base] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = m - 1; i >= 0; i--) {
				for (int j = 0; j <= 2 * base; j++) {
					if (dp[i][j] >= 0) {
						if (j + s[k] > 2 * base)continue;
						if (dp[i + 1][j + s[k]] < dp[i][j]+p[k]) {
							dp[i + 1][j + s[k]] = dp[i][j] + p[k];
							path[i + 1][j + s[k]] = path[i][j];
							path[i + 1][j + s[k]].push_back(k);
						}
					}
				}
			}
		}
		int v = 0;
		for (; dp[m][base + v] == -1 && dp[m][base - v] == -1; v++);
		int tmp = dp[m][base + v] > dp[m][base - v] ? v : -v;
		int sumP, sumD;
		sumP = (dp[m][base + tmp] + tmp) / 2;
		sumD = (dp[m][base + tmp] - tmp) / 2;
		printf("Jury #%d\n", cas++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", sumP, sumD);
		for (int i = 0; i < path[m][base + tmp].size(); i++)
			printf(" %d", path[m][base + tmp][i]+1);
		printf("\n\n");
	}
	system("pause");
	return 0;
}