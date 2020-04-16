#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 2e3 + 5;
int fa[N], val[N];
int findfa(int x) {
	if (fa[x] != x) {
		int t = fa[x];
		fa[x] = findfa(t);
		val[x] += val[t];
	}
	return fa[x];
}
int main() {
	int n, m, cas;
	cin >> cas;
	int id = 1;
	while (cas--) {
		bool flag = false;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		memset(val, 0,sizeof(val));
		for (int i = 0; i < m; i++) {
			int t1, t2;
			scanf("%d%d", &t1, &t2);
			int f1 = findfa(t1);
			int f2 = findfa(t2);
			if (f1 == f2) {
				if (abs(val[t1] - val[t2]) % 2 == 0)
					flag = true;
			}
			else {
				fa[f1] = f2;
				val[f1] = val[t2] - val[t1] + 1;
			}
		}
		if (flag)
			printf("Scenario #%d:\nSuspicious bugs found!\n", id++);
		else
			printf("Scenario #%d:\nNo suspicious bugs found!\n", id++);
		cout << endl;
	}

	system("pause");
	return 0;
}