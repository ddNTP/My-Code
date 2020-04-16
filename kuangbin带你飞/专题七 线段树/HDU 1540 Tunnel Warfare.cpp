#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 5e4 + 5;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
struct Node
{
	int lmax, rmax, ans;
}node[N<<2];
int rec[N];
void pushup(int rt,int l,int r) {
	Node &root = node[rt], &lr = node[rt << 1], &rr = node[rt << 1 | 1];
	int mid = (l + r) / 2;
	root.lmax = lr.lmax + (lr.lmax == (mid - l + 1) ? rr.lmax : 0);
	root.rmax = rr.rmax + (rr.rmax == (r - mid) ? lr.rmax : 0);
	root.ans = max(max(lr.ans, rr.ans), lr.rmax + rr.lmax);
}
void build(int l, int r, int rt) {
	if (l == r) {
		node[rt].lmax = node[rt].rmax = node[rt].ans = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	pushup(rt, l, r);
}
void update(int x, int c, int l, int r, int rt) {
	if (l == r){
		node[rt].lmax = node[rt].rmax = node[rt].ans = c;
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid)
		update(x, c, lson);
	else
		update(x, c, rson);
	pushup(rt, l, r);
}
int query(int x, int l, int r, int rt) {
	if (l == r || node[rt].ans == 0)
		return node[rt].ans;
	int mid = (l + r) / 2;
	if (x <= mid) {
		if (node[rt << 1].rmax >=mid-x+1) {
			return node[rt << 1].rmax + node[rt << 1 | 1].lmax;
		}
		else
			return query(x, lson);
	}
	else {
		if (node[rt << 1 | 1].lmax >= x - mid) {
			return node[rt << 1 | 1].lmax + node[rt << 1].rmax;
		}
		else
			return query(x, rson);
	}
}
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		build(1, n, 1);
		int last = 0;
		for (int i = 0; i < m; i++) {
			getchar();
			char ch;
			int a;
			scanf("%c", &ch);
			if (ch == 'D') {
				scanf("%d", &a);
				update(a, 0, 1, n, 1);
				rec[++last] = a;
			}
			else if (ch == 'Q') {
				scanf("%d", &a);
				printf("%d\n", query(a, 1, n, 1));
			}
			else
				update(rec[last--], 1, 1, n, 1);
		}
	}
	system("pause");
	return 0;
}