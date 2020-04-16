#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 5e4 + 5;
int maxn[N << 2], minn[N << 2];
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
void pushup(int rt) {
	maxn[rt] = max(maxn[rt << 1], maxn[rt << 1 | 1]);
	minn[rt] = min(minn[rt << 1], minn[rt << 1 | 1]);
}
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &maxn[rt]);
		minn[rt] = maxn[rt];
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	pushup(rt);
}
int querymax(int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R)return maxn[rt];
	int ans = 0, mid = (l + r) / 2;
	if (L <= mid)ans = max(ans, querymax(L, R, lson));
	if (R > mid)ans = max(ans, querymax(L, R, rson));
	return ans;
}
int querymin(int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R)return minn[rt];
	int ans = 0x3f3f3f3f, mid = (l + r) / 2;
	if (L <= mid)ans = min(ans, querymin(L, R, lson));
	if (R > mid)ans = min(ans, querymin(L, R, rson));
	return ans;
}
int main() {
	int n, q;
	cin >> n >> q;
	build(1, n, 1);
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int t1 = querymax(a, b, 1, n, 1);
		int t2 = querymin(a, b, 1, n, 1);
		printf("%d\n", t1 - t2);
	}
	system("pause");
	return 0;
}