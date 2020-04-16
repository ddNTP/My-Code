#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 3e4 + 5;
int fa[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
void unio(int x, int y) {
	int fx = findfa(x);
	int fy = findfa(y);
	fa[fx] = fy;
}
int main() {
	int n, m;
	cin >> n >> m;
	while (n != 0) {
		for (int i = 0; i < n; i++)
			fa[i] = i;
		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;
			if (k == 0)continue;
			int t1,t2;
			cin >> t1;
			for (int j = 1; j < k; j++) {
				scanf("%d", &t2);
				unio(t1, t2);
			}
		}
		int x = findfa(0);
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (findfa(i) == x)ans++;
		cout << ans << endl;
		cin >> n >> m;
	}
	system("pause");
	return 0;
}