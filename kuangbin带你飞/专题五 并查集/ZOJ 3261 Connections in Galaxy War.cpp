#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N = 1e4 + 5, M = 2e4 + 5, Q = 5e4 + 5;
int w[N], p[N], ans[Q];
#define P pair<int,int>
struct edge
{
	int x, y;
}e[M];
struct Node
{
	int x, y;
	char s[8];
}node[Q];
int findp(int x) {
	return x == p[x] ? x : (p[x] = findp(p[x]));
}
void unio(int x, int y) {
	int f1 = findp(x);
	int f2 = findp(y);
	if (f1 == f2)return;
	else {
		if (w[f1] > w[f2])p[f2] = f1;
		else if (w[f2] > w[f1])p[f1] = f2;
		else {
			if (f1 > f2)p[f1] = f2;
			else p[f2] = f1;
		}
	}
}

int main() {
	int n, m, q;
	bool flag = true;
	while (scanf("%d", &n) != EOF) {
		if (flag)flag = false;
		else printf("\n");
		map<P, int>mp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
			p[i] = i;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d", &e[i].x, &e[i].y);
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			scanf("%s", node[i].s);
			if (node[i].s[0] == 'q')
				scanf("%d", &node[i].x);
			else {
				scanf("%d%d", &node[i].x, &node[i].y);
				mp[P(node[i].x, node[i].y)] = 1;
				mp[P(node[i].y, node[i].x)] = 1;
			}
		}
		for (int i = 0; i < m; i++) {
			if (mp[P(e[i].x, e[i].y)])continue;
			unio(e[i].x, e[i].y);
		}
		int cnt = 0;
		for (int i = q - 1; i >= 0; i--) {
			if (node[i].s[0] == 'd') 
				unio(node[i].x, node[i].y);
			else {
				int t = findp(node[i].x);
				if (w[t] > w[node[i].x]) {
					ans[++cnt] = t;
				}
				else
					ans[++cnt] = -1;
			}
		}
		for (int i = cnt; i > 0; i--)
			printf("%d\n", ans[i]);
	}
	system("pause");
	return 0;
}