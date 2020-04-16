#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 505, M = 10005, inf = 0x3f3f3f3f;
int n, weight;
int dp[M];
struct Node
{
	int w, v;
}node[N];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int t1, t2;
		cin >> t1 >> t2;
		weight= t2 - t1;
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> node[i].v >> node[i].w;
		memset(dp, inf, sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i <= weight; i++) 
			for (int j = 0; j < n; j++) 
				if (i - node[j].w >= 0) 
					dp[i] = min(dp[i], dp[i - node[j].w] + node[j].v);
		if (dp[weight] == inf)cout << "This is impossible.\n";
		else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[weight]);
	}
	system("pause");
	return 0;
}