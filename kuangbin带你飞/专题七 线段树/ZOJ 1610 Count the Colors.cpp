#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 8e3 + 5;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int color[N << 2];
int seg[N], fin[N];
void pushdown(int rt) {
	if (color[rt]!=-1) {
		color[rt << 1] = color[rt << 1 | 1] = color[rt];
		color[rt] = -1;
	}
}
void update(int L, int R, int c, int l, int r, int rt) {
	if (l >= L && r <= R) {
		color[rt] = c;
		return;
	}
	pushdown(rt);
	int mid = (l + r) / 2;
	if (L <= mid)update(L, R, c, lson);
	if (R > mid)update(L, R, c, rson);
}
int query(int c, int l, int r, int rt) {
	if (l == r)return color[rt];
	pushdown(rt);
	int mid = (l + r) / 2;
	if (c <= mid)return query(c, lson);
	else return query(c, rson);
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(color, -1, sizeof(color));
		memset(seg, 0, sizeof(seg));
		memset(fin, -1, sizeof(fin));
		for (int i = 0; i < n; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			update(a+1, b, c, 1, N, 1);
		}
		for (int i = 1; i < N; i++)
			fin[i] = query(i, 1, N, 1);
		for (int i = 1; i < N; ) {
			while (i < N&&fin[i] == -1)i++;
			if (i >= N)break;
			int last = fin[i];
			i++;
			for (; i < N; i++) 
				if (fin[i] != last)break;
			seg[last]++;
		}
		for (int i = 0; i < N; i++)
			if (seg[i])printf("%d %d\n", i, seg[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}