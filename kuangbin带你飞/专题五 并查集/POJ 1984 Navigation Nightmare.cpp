#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 4e4 + 5, K = 1e4 + 5;
int fa[N], dx[N], dy[N], ans[K];
struct Node
{
	int u, v, i, id;
	bool operator<(const Node&a)const {
		return id < a.id;
	}
}node[K];
struct Node2
{
	int u, v, x, y;
}node2[N];
int findfa(int x) {
	if (x != fa[x]) {
		int t = fa[x];
		fa[x] = findfa(t);
		dx[x] += dx[t];
		dy[x] += dy[t];
	}
	return fa[x];
}
int main() {
	int n, m;
	cin >> n >> m;
	char str[4];
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	int L;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%s", &node2[i].u, &node2[i].v, &L, str);
		if (str[0] == 'W')node2[i].x -= L;
		else if (str[0] == 'E')node2[i].x += L;
		else if (str[0] == 'N')node2[i].y += L;
		else node2[i].y -= L;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d", &node[i].u, &node[i].v, &node[i].id);
		node[i].i = i;
	}
	sort(node, node + k);
	for (int i = 0, j = 0; i < k; i++) {
		while (j < node[i].id) {
			int t1 = node2[j].u;
			int t2 = node2[j].v;
			int x = node2[j].x, y = node2[j].y;
			int f1 = findfa(t1);
			int f2 = findfa(t2);
			if (f1 != f2) {
				fa[f1] = f2;
				dx[f1] = dx[t2] - dx[t1] + x;
				dy[f1] = dy[t2] - dy[t1] + y;
			}
			j++;
		}
		if (findfa(node[i].u) == findfa(node[i].v))
			ans[node[i].i] = abs(dx[node[i].u] - dx[node[i].v]) + abs(dy[node[i].u] - dy[node[i].v]);
		else
			ans[node[i].i] = -1;
	}
	for (int i = 0; i < k; i++)
		printf("%d\n", ans[i]);
	system("pause");
	return 0;
}