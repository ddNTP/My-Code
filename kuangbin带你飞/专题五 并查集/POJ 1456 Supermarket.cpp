#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e4 + 5;
int fa[N];
struct Node
{
	int p, d;
	bool operator<(const Node &a)const {
		return p > a.p;
	}
}node[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < N; i++)
			fa[i] = i;
		for (int i = 0; i < n; i++)
			scanf("%d %d", &node[i].p, &node[i].d);
		sort(node, node + n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int t = findfa(node[i].d);
			if (t > 0) {
				ans += node[i].p;
				fa[t] = t - 1;
			}
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}