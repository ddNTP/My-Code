#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 5e4 + 5;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define mm(a,b) memset(a,b,sizeof(a))
int work[N << 2], p[N], in[N], out[N], h[N], cnt, n, root, index, m;
struct Edge
{
	int v, next;
}e[N];
void add(int u, int v) {
	e[++cnt].next = h[u];
	e[cnt].v = v;
	h[u] = cnt;
}
void dfs(int u) {
	in[u] = ++index;
	for (int i = h[u]; i; i = e[i].next) 
		dfs(e[i].v);
	out[u] = index;
}
void pushdown(int rt) {
	if (work[rt] != -1) {
		work[rt << 1] = work[rt << 1 | 1] = work[rt];
		work[rt] = -1;
	}
}
void build(int l, int r, int rt) {
	if (l == r) {
		work[rt] = -1;
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	work[rt] = -1;
}
void update(int L, int R, int c, int l, int r, int rt) {
	if (l >= L && r <= R) {
		work[rt] = c;
		return;
	}
	pushdown(rt);
	int mid = (l + r) / 2;
	if (L <= mid)update(L, R, c, lson);
	if (R > mid)update(L, R, c, rson);
}
int query(int x, int l, int r, int rt) {
	if (l == r)return work[rt];
	pushdown(rt);
	int mid = (l + r) / 2;
	if (x <= mid)return query(x, lson);
	else return query(x, rson);
}
int main() {
	int T, cas = 1;
	cin >> T;
	while (T--) {
		printf("Case #%d:\n", cas++);
		cnt = 0, index = 0;
		mm(h, 0);
		mm(p, -1);
		cin >> n;
		build(1, n, 1);
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			p[a] = b;
			add(b, a);
		}
		for (int i = 1; i <= n; i++)
			if (p[i] == -1)root = i;
		dfs(root);
		cin >> m;
		char ch;
		int a, b;
		for (int i = 0; i < m; i++) {
			getchar();
			scanf("%c", &ch);
			if (ch == 'C') {
				scanf("%d", &a);
				printf("%d\n", query(in[a], 1, n, 1));
			}
			else {
				scanf("%d%d", &a, &b);
				update(in[a], out[a], b, 1, n, 1);
			}
		}
	}
	system("pause");
	return 0;
}
