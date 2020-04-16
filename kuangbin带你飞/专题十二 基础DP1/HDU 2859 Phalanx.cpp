#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1005;
char a[N][N];
int n, dp[N][N];
int main() {
	while (cin >> n) {
		if (n == 0)break;
		for (int i = 0; i < n; i++) {
			getchar();
			scanf("%s", a[i]);
		}
		fill(dp[0], dp[0] + N * N, 1);
		int ans = 1;
		for (int i = 1; i <n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				int k = 1;
				for (; k <= dp[i - 1][j + 1]; k++)
					if (a[i - k][j] != a[i][j + k])break;
				dp[i][j] = k;
				ans = max(dp[i][j], ans);
			}
		}
		cout << ans << endl;
		
	}
	system("pause");
	return 0;
}