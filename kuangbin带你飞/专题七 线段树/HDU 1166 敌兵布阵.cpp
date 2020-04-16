#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;
const int N = 1e5 + 5;
int sum[N << 2], add[N << 2];
void pushup(int rt) {
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}
void pushdown(int rt, int m) {
	if (add[rt]) {
		add[rt * 2] += add[rt];
		add[rt * 2 + 1] += add[rt];
		sum[rt * 2] += (m - (m / 2))*add[rt];
		sum[rt * 2 + 1] += m / 2 * add[rt];
		add[rt] = 0;
	}
}
void build(int l, int r, int rt) {
	add[rt] = 0;
	if (l == r) {
		scanf("%d", &sum[rt]);
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt * 2 + 1);
	pushup(rt);
}
void update(int L, int R, int l, int r, int key,int rt) {
	if (l >= L && R >= r) {
		sum[rt] += (r - l + 1)*key;
		add[rt] += key;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(rt, l - r + 1);
	if (L <= mid)update(L, R, l, mid, key, rt * 2);
	if (R > mid)update(L, R, mid + 1, r, key, rt * 2 + 1);
	pushup(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R) 
		return sum[rt];
	int mid = (l + r) / 2;
	pushdown(rt, l - r + 1);
	int ans = 0;
	if (L <= mid)ans += query(L, R, l, mid, rt * 2);
	if (R > mid)ans += query(L, R, mid + 1, r, rt * 2 + 1);
	return ans;
}
int main() {
	int T;
	int cas = 1;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		build(1, n, 1);
		printf("Case %d:\n", cas++);
		char str[10];
		getchar();
		while (scanf("%s", str)) {
			if (str[0] == 'E')break;
			int a,b;
			scanf("%d%d", &a, &b);
			if (str[0] == 'Q')printf("%d\n", query(a, b, 1, n, 1));
			else if (str[0] == 'A')update(a, a, 1, n, b, 1);
			else if (str[0] == 'S')update(a, a, 1, n, -b, 1);
			getchar();
		}
	}
	system("pause");
	return 0;
}