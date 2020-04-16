#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 2e5 + 5;
int fa[N], sum[N];
int findfa(int x) {
	if (x != fa[x]) {
		int t = fa[x];
		fa[x] = findfa(fa[x]);
		sum[x] += sum[t];
	}
	return fa[x];
}
void unio(int x, int y,int v) {
	int fx = findfa(x);
	int fy = findfa(y);
	if (fx != fy) {
		fa[fx] = fy;
		sum[fx] = sum[y] - sum[x] + v;
	}
}
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i <= n; i++)
			fa[i] = i;
		memset(sum, 0, sizeof(sum));
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			t1--;
			int f1 = findfa(t1);
			int f2 = findfa(t2);
			if (f1 == f2) {
				if (sum[t1] != sum[t2] + t3)
					ans++;
			}
			else 
				unio(t1, t2, t3);
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
 }