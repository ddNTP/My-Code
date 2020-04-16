
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N = 1e5 + 5;
ll sum[N << 2], add[N << 2];
void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt, int m) {
	if (add[rt]) {
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += (m - (m >> 1))*add[rt];
		sum[rt << 1 | 1] += m / 2 * add[rt];
		add[rt] = 0;
	}
}
void build(int l, int r, int rt) {
	add[rt] = 0;
	if (l == r) {
		scanf("%lld", &sum[rt]);
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int L,int R,ll c,int l,int r,int rt) {
	if (l >= L && r <= R) {
		add[rt] += c;
		sum[rt] += (r - l + 1)*c;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(rt, r - l + 1);
	if (L <= mid)update(L, R, c, lson);
	if (R > mid)update(L, R, c, rson);
	pushup(rt);
}
ll query(int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R) 
		return sum[rt];
	int mid = (l + r) / 2;
	pushdown(rt, r - l + 1);
	ll ans = 0;
	if (L <= mid)ans += query(L, R, lson);
	if (R > mid)ans += query(L, R, rson);
	return ans;
}
int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	build(1, n, 1);
	for (int i = 0; i < q; i++) {
		getchar();
		char ch;
		int a, b;
		ll c;
		scanf("%c", &ch);
		if (ch == 'Q') {
			scanf("%d%d", &a, &b);
			printf("%lld\n", query(a, b, 1, n, 1));
		}
		else {
			scanf("%d%d%lld", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
	}
	system("pause");
	return 0;
}
