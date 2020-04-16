#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 2e5 + 5;
int fa[N], have[N], root[N], num[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
int main() {
	int cas = 1;
	int t1, t2;
	while (scanf("%d%d", &t1, &t2)) {
		if (t1 == -1 && t2 == -1)
			break;
		for (int i = 0; i < N; i++) 
			fa[i] = i;
		memset(have, 0, sizeof(have));
		memset(num, 0, sizeof(num));
		memset(root, 0, sizeof(root));
		if (t1 == 0 && t2 == 0) {
			printf("Case %d is a tree.\n", cas++);
			continue;
		}
		have[t2] = 1;
		have[t1] = 1;
		num[t2]++;
		bool flag = true;
		fa[t2] = t1;
		while (scanf("%d%d", &t1, &t2)) {
			if (t1 == 0 && t2 == 0) {
				if (!flag) {
					printf("Case %d is not a tree.\n", cas++);
					break;
				}
				int cnt = 0, r = -1;
				for (int i = 0; i < N; i++) {
					if (have[i] && !num[i]) {
						cnt++;
						r = i;
					}
				}
				if (cnt != 1) {
					printf("Case %d is not a tree.\n", cas++);
					break;
				}
				for (int i = 0; i < N; i++) 
					if (have[i])root[findfa(i)]++;
				cnt = 0;
				int r1 = -1;
				for (int i = 0; i < N; i++)
					if (root[i]) {
						cnt++;
						r1 = i;
					}
				if (cnt != 1||r1!=r) {
					printf("Case %d is not a tree.\n", cas++);
					break;
				}
				printf("Case %d is a tree.\n", cas++);
				break;
			}
			have[t2] = 1;
			have[t1] = 1;
			num[t2]++;
			if (num[t2] > 1)flag = false;
			fa[t2] = t1;
		}
	}
	system("pause");
	return 0;
}