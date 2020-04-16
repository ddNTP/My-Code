#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
int sum[N << 2], add[N << 2];
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt, int m) {
	if (add[rt]) {
		add[rt << 1] = add[rt << 1 | 1] = add[rt];
		sum[rt << 1] = (m - m / 2)*add[rt];
		sum[rt << 1 | 1] = m / 2 * add[rt];
		add[rt] = 0;
	}
}
void build(int l, int r, int rt) {
	add[rt] = 0;
	if (l == r) {
		sum[rt] = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int L, int R, int c, int l, int r, int rt) {
	if (l >= L && r <= R) {
		sum[rt] = c * (r - l + 1);
		add[rt] = c;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(rt, r - l + 1);
	if (L <= mid)update(L, R, c, lson);
	if (R > mid)update(L, R, c, rson);
	pushup(rt);
}
int main() {
	int T, cas = 1;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		build(1, n, 1);
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", cas++, sum[1]);
	}
	system("pause");
	return 0;
}