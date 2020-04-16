#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
char a[1005], b[1005];
int dp[1005][1005];
int main() {
	while (scanf("%s %s", a, b) != EOF) {
		int la = strlen(a), lb = strlen(b);
		for (int i = 0; i < la; i++)dp[i][0] = 0;
		for (int i = 0; i < lb; i++)dp[0][i] = 0;
		for (int i = 1; i <= la; i++) {
			for (int j = 1; j <= lb; j++) {
				if (a[i-1] != b[j-1])dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				else dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
		cout << dp[la][lb] << endl;
	}
	system("pause");
	return 0;
}