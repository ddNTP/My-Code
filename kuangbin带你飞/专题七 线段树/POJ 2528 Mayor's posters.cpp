#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int color[N << 2], vis[N << 2], rl[N], rr[N], lisan[N];
void pushdown(int rt) {
	if (color[rt] != -1) {
		color[rt << 1] = color[rt << 1 | 1] = color[rt];
		color[rt] = -1;
	}
}
void update(int L, int R, int c, int l, int r, int rt) {
	if (l >= L && r <= R) {
		color[rt] = c;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(rt);
	if (L <= mid)update(L, R, c, lson);
	if (R > mid)update(L, R, c, rson);

}
int query(int L, int R,int l,int r, int rt) {
	if (l >= L && r <= R && color[rt] != -1) {
		if (!vis[color[rt]]) {
			vis[color[rt]] = 1;
			return 1;
		}
		else return 0;
	}
	if (l == r)return 0;
	int ans = 0, mid = (l + r) / 2;
	if (L <= mid)ans+=query(L, R, lson);
	if (R > mid)ans+=query(L, R, rson);
	return ans;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(color, -1, sizeof(color));
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &rl[i], &rr[i]);
			lisan[++cnt] = rl[i];
			lisan[++cnt] = rr[i];
		}
		sort(lisan + 1, lisan + cnt + 1);
		int t = unique(lisan + 1, lisan + cnt + 1) - lisan - 1;
		int m = t;
		for (int i = 1; i < t; i++) 
			if (lisan[i + 1] - lisan[i] > 1) 
				lisan[++m] = lisan[i] + 1;
		cnt = m;
		sort(lisan + 1, lisan + cnt + 1);
		for (int i = 0; i < n; i++) {
			int L = lower_bound(lisan + 1, lisan + cnt + 1, rl[i]) - lisan;
			int R = lower_bound(lisan + 1, lisan + cnt + 1, rr[i]) - lisan;
			update(L, R, i, 1, cnt, 1);
		}
		printf("%d\n", query(1, cnt, 1, cnt, 1));
		
	}
	system("pause");
	return 0;
}