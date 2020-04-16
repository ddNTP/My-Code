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
int sum[N << 2], lazy[N << 2], n, m;
void pushdown(int rt,int m) {
	if (lazy[rt] != -1) {
		sum[rt << 1] = (m - m / 2)*lazy[rt];
		sum[rt << 1 | 1] = m / 2 * lazy[rt];
		lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
		lazy[rt] = -1;
	}
}
void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = 1;
		lazy[rt] = -1;
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	lazy[rt] = -1;
	pushup(rt);
}
void update(int L, int R,int c,int l, int r, int rt) {
	if (l == r || l >= L && r <= R) {
		sum[rt] = (r - l + 1)*c;
		lazy[rt] = c;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(rt, r - l + 1);
	if (L <= mid)update(L, R, c, lson);
	if (R > mid)update(L, R, c, rson);
	pushup(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if (l == r || l >= L && r <= R)
		return sum[rt];
	int mid = (l + r) / 2;
	pushdown(rt, r - l + 1);
	int ans = 0;
	if (L <= mid)ans += query(L, R, lson);
	if (R > mid)ans += query(L, R, rson);
	return ans;
}
int binarysearch(int l, int r, int x) {
	while (l < r) {
		int mid = (l + r) / 2;
		int t = query(l, mid, 1, n, 1);
		if (x <= t)r = mid;
		else {
			x -= t;
			l = mid + 1;
		}
	}
	return r;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		build(1, n, 1);
		for (int i = 0; i < m; i++) {
			int op, l, r;
			scanf("%d%d%d", &op, &l, &r);
			l++;
			if (op == 1) {
				int t = query(l, n, 1, n, 1);
				if (t==0)
					printf("Can not put any one.\n");
				else {
					r = min(r, t);
					int lans = binarysearch(l, n, 1);
					int rans = binarysearch(l, n, r);
					printf("%d %d\n", lans-1, rans-1);
					update(lans, rans, 0, 1, n, 1);
				}
			}
			else {
				r++;
				int t = query(l, r, 1, n, 1);
				update(l, r, 1, 1, n, 1);
				printf("%d\n", r - l + 1 - t);
			}
		
		}
		printf("\n");
	}
	system("pause");
	return 0;
}