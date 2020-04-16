#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define fill(a,b) fill(a,a+sizeof(a)/sizeof(int),b)
int dp[1005];
int num[1005];
int nn[10][10];
int main() {
	int n;
	cin >> n;
	fill(dp, 1);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 1; i < n; i++) 
		for (int j = 0; j < i; j++) 
			if (num[i] > num[j])
				dp[i] = max(dp[i], dp[j] + 1);
	int ans = dp[0];
	for (int i = 1; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	system("pause");
	return 0;
}