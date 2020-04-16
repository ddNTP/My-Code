#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[181];
struct node
{
	int x, y, z;
	node(int i,int j,int k):x(i),y(j),z(k){}
	bool operator<(const node&a)const {
		if (x == a.x)return y < a.y;
		else return x < a.x;
	}
};
int main() {
	int n;
	int cas = 1;
	while (scanf("%d", &n) != EOF) {
		if (n == 0)break;
		vector<node>q;
		for (int i = 0; i < n; i++) {
			int t1, t2, t3;
			scanf("%d%d%d", &t1, &t2, &t3);
			q.push_back(node(t1, t2, t3));
			q.push_back(node(t2, t1, t3));
			q.push_back(node(t1, t3, t2));
			q.push_back(node(t3, t1, t2));
			q.push_back(node(t2, t3, t1));
			q.push_back(node(t3, t2, t1));
		}
		sort(q.begin(), q.end());
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for (int j = 0; j < q.size(); j++)
			dp[j] = q[j].z;
		for (int j = 0; j < q.size(); j++) {
			for (int k = j + 1; k < q.size(); k++) {
				if (q[k].x > q[j].x&&q[k].y > q[j].y) {
					dp[k] = max(dp[k], dp[j] + q[k].z);
					ans = max(ans, dp[k]);
				}
			}
		}
		printf("Case %d: maximum height = %d\n", cas++, ans);
	}
	system("pause");
	return 0;
}