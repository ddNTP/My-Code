#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
const int N = 5e4 + 5;
int fa[N], val[N];
int findfa(int x) {
	if (x != fa[x]) {
		int t = fa[x];
		fa[x] = findfa(fa[x]);
		val[x] = (val[x] + val[t]) % 3;
	}
	return fa[x];
}
int main() {
	int ans = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		fa[i] = i;
	for (int i = 0; i < k; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t2 > n || t3 > n) {
			ans++;
			continue;
		}
		if (t2 == t3 && t1 == 2) {
			ans++;
			continue;
		}
		t1--;
		int x = findfa(t2);
		int y = findfa(t3);
		if (x == y) {
			if ((val[t2] - val[t3] + 3) % 3 != t1)ans++;
		}
		else {
			fa[x] = y;
			val[x] = (val[t3] - val[t2] + t1 + 3) % 3;
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}