#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5, mod = 10007;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ll long long 
int val[N << 2];
void pushdown(int rt) {
	if (val[rt] != -1) {
		val[rt << 1] = val[rt << 1 | 1] = val[rt];
		val[rt] = -1;
	}
}
void pushup(int rt) {
	val[rt] = val[rt << 1] == val[rt << 1 | 1] ? val[rt << 1] : -1;
}
void build(int l, int r, int rt) {
	if (l == r) {
		val[rt] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	val[rt] = 0;
}
void update(int op, int L, int R, int c, int l, int r, int rt) {
	if (l == r||l>=L&&r<=R&&val[rt]!=-1) {
		if (op == 1)val[rt] = (val[rt] + c) % mod;
		else if (op == 2)val[rt] = (val[rt] * c) % mod;
		else val[rt] = c;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(rt);
	if (L <= mid)update(op, L, R, c, lson);
	if (R > mid)update(op, L, R, c, rson);
	pushup(rt);
}
int query(int p,int L,int R,int l,int r,int rt) {
	if (l == r || l >= L && r <= R && val[rt] != -1) 
		return (ll)pow(val[rt], p)*(r - l + 1) % mod;
	int mid = (l + r) / 2;
	pushdown(rt);
	int ans = 0;
	if (L <= mid)ans += query(p, L, R, lson);
	if (R > mid)ans += query(p, L, R, rson);
	return ans % mod;
}
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0)break;
		build(1, n, 1);
		int op, l, r, x;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d%d", &op, &l, &r, &x);
			if (op <= 3)update(op, l, r, x, 1, n, 1);
			else printf("%d\n", query(x, l, r, 1, n, 1));
		}
	}
	system("pause");
	return 0;
}