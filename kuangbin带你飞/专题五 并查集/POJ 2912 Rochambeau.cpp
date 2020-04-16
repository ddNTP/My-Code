#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 505, M = 2005;
int fa[N], val[N], pos[N];

int findfa(int x) {
	if (x != fa[x]) {
		int t = fa[x];
		fa[x] = findfa(t);
		val[x] = (val[x] + val[t]) % 3;
	}
	return fa[x];
}
struct Node
{
	int u, v, w;
}node[M];
bool merge(int u, int v, int w) {
	int f1 = findfa(u);
	int f2 = findfa(v);
	if (f1 == f2 && (val[u] - val[v] + 3) % 3 != w)
		return false;
	else if(f1!=f2){
		fa[f1] = f2;
		val[f1] = (val[v] - val[u] + w + 3) % 3;
	}
	return true;
}
int main() {
	int n, m;
	char c;
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(pos, 0, sizeof(pos));
		for (int i = 1; i <= m; i++) {
			scanf("%d%c%d", &node[i].u, &c, &node[i].v);
			if (c == '<')node[i].w = 1;
			else if (c == '>')node[i].w = 2;
			else node[i].w = 0;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k <= n; k++)
				fa[k] = k;
			memset(val, 0, sizeof(val));
			for (int j = 1; j <= m; j++) {
				if (node[j].u == i || node[j].v == i)continue;
				if (!merge(node[j].u, node[j].v, node[j].w)) {
					pos[i]=j;
					break;
				}
			}
		}
		int id = 0;
		int line = 0;
		for (int i = 0; i < n; i++) {
			if (!pos[i]) {
				cnt++;
				id = i;
			}
			line = max(line, pos[i]);
		}
		if (cnt == 0)printf("Impossible\n");
		else if (cnt > 1)printf("Can not determine\n");
		else printf("Player %d can be determined to be the judge after %d lines\n", id, line);
		
	}
	system("pause");
	return 0;
}