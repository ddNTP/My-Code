#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1005;
int dp[N], num[N];
int main() {
	int n;
	while (cin >> n) {
		if (n == 0)break;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			dp[i] = num[i];
			for (int j = 0; j <= i - 1; j++) {
				if (num[j]<num[i] && dp[j] + num[i]>dp[i]) {
					dp[i] = dp[j] + num[i];
				}
			}
		}
		for (int i = 0; i < n; i++)
			ans = max(ans, dp[i]);
		cout << ans << endl;
	}
	system("pause");
	return 0;
}