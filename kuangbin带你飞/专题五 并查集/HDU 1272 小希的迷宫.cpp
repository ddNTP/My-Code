#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 + 5;
int fa[N], have[N], root[N];
int findfa(int x) {
	return fa[x] == x ? x : (fa[x] = findfa(fa[x]));
}
void unio(int x, int y) {
	int f1 = findfa(x);
	int f2 = findfa(y);
	if (f1 != f2)
		fa[f1] = f2;
}
int main() {
	int t1, t2;
	while (scanf("%d%d", &t1, &t2)) {
		memset(have, 0, sizeof(have));
		memset(root, 0, sizeof(root));
		if (t1 == -1 && t2 == -1)break;
		if (t1 == 0 && t2 == 0) {
			printf("Yes\n");
			continue;
		}
		for (int i = 0; i < N; i++)
			fa[i] = i;
		unio(t1, t2);
		have[t1] = 1;
		have[t2] = 1;
		bool flag = true;
		while (scanf("%d%d", &t1, &t2)) {
			if (t1 == 0 && t2 == 0) {
				if (!flag)printf("No\n");
				else {
					for (int i = 1; i < N; i++) {
						if (have[i])
							root[findfa(i)]++;
					}
					int cnt = 0;
					for (int i = 1; i < N; i++)
						if (root[i])cnt++;
					if (cnt == 1)printf("Yes\n");
					else printf("No\n");
				}
				break;
			}
			have[t1] = 1;
			have[t2] = 1;
			int f1 = findfa(t1);
			int f2 = findfa(t2);
			if (f1 == f2)
				flag = false;
			else
				fa[f1] = f2;
		}
	}
	system("pause");
	return 0;
}