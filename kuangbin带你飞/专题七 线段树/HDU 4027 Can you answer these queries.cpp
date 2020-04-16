#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ll long long
const int N = 1e5 + 5;
ll sum[N << 2];
int n;
void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%lld", &sum[rt]);
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int L, int R, int l, int r, int rt) {
	if (l == r) {
		sum[rt] = sqrt(sum[rt]);
		return;
	}
	if (l >= L && r <= R) {
		if (sum[rt] != r - l + 1) {
			int mid = (l + r) / 2;
			update(L, R, lson);
			update(L, R, rson);
			pushup(rt);
		}
		return;
	}
	int mid = (l + r) / 2;
	if (L <= mid)update(L, R, lson);
	if (R > mid)update(L, R, rson);
	pushup(rt);
}

ll query(int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R) 
		return sum[rt];
	int mid = (l + r) / 2;
	ll ans = 0;
	if (L <= mid)ans += query(L, R, lson);
	if (R > mid)ans += query(L, R, rson);
	return ans;
}
int main() {
	int cas = 1;
	while (scanf("%d", &n) != EOF) {
		build(1, n, 1);
		int m;
		cin >> m;
		printf("Case #%d:\n", cas++);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (b > c)swap(b, c);
			if (a == 0) {
				update(b, c, 1, n, 1);
			}
			else {
				printf("%lld\n", query(b, c, 1, n, 1));
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}