#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
const int inf = 0x3f3f3f3f, maxn = 1 << 15;
struct Node
{
	string name;
	int ddl, tim;
}node[20];
int n, dp[maxn], tim[maxn], pre[maxn];
void print(int x) {
	if (x == 0)return;
	print(x - (1 << pre[x]));
	cout << node[pre[x]].name << endl;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> node[i].name >> node[i].ddl >> node[i].tim;
		mm(dp, 0);
		mm(tim, 0);
		mm(pre, 0);
		int total = 1 << n;
		for (int i = 1; i < total; i++) {
			dp[i] = inf;
			for (int j = n-1; j>=0; j--) {
				int tmp = 1 << j;
				if (!(i&tmp))continue;
				int s = tim[i - tmp] + node[j].tim - node[j].ddl;
				s = max(s, 0);
				if (dp[i] > dp[i - tmp] + s) {
					dp[i] = dp[i - tmp] + s;
					tim[i] = tim[i - tmp] + node[j].tim;
					pre[i] = j;
				}
			}
		}
		cout << dp[total - 1] << endl;
		print(total - 1);
	}
	system("pause");
	return 0;
}