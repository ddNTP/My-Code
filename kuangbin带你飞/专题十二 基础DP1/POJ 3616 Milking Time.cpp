#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1005;
struct Node
{
	int l, r, w;
	bool operator<(const Node&a)const {
		return l < a.l;
	}
}node[N];
int dp[N];
int main() {
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) 
		cin >> node[i].l >> node[i].r >> node[i].w;
	sort(node, node + m);
	for (int i = 0; i < m; i++) {
		dp[i] = node[i].w;
		for (int j = 0; j < i; j++) {
			if (node[j].r + r <= node[i].l)
				dp[i] = max(dp[i], dp[j] + node[i].w);
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	system("pause");
	return 0;
}