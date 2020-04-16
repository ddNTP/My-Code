#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e4 + 5;
int fa[N], val[N], judge[N], tmp1[N], tmp2[N], cnt;
int findfa(int x) {
	if (fa[x] != x) {
		int t = fa[x];
		fa[x] = findfa(fa[x]);
		val[x] += val[t];
	}
	return fa[x];
}
int main() {
	char str[6];
	int L, Q;
	cin >> L >> Q;
	
	int ans = 0;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %s", &tmp1[i*2], &tmp1[i*2+1], str);
		tmp1[i * 2]--;
		if (str[0] == 'o')judge[i] = 1;
		tmp2[i * 2] = tmp1[i * 2];
		tmp2[i * 2 + 1] = tmp1[i * 2 + 1];
	}
	sort(tmp2, tmp2 + 2 * Q);
	cnt = unique(tmp2, tmp2 + 2 * Q) - tmp2;
	for (int i = 0; i <= cnt; i++)
		fa[i] = i;
	for (int i = 0; i < 2 * Q; i++)
		tmp1[i] = lower_bound(tmp2, tmp2 + cnt, tmp1[i]) - tmp2;
	for (int i = 0; i < Q; i++) {
		int t1 = tmp1[2 * i];
		int t2 = tmp1[2 * i + 1];
		int f1 = findfa(t1);
		int f2 = findfa(t2);
		if (judge[i]==0) {
			if (f1 == f2) {
				if (abs(val[t1] - val[t2]) % 2 == 1 && !ans) {
					ans = i;
				}
			}
			else {
				fa[f1] = f2;
				val[f1] = val[t2] - val[t1];
			}
		}
		else {
			if (f1 == f2) {
				if (abs(val[t1] - val[t2]) % 2 == 0 && !ans) {
					ans = i;
				}
			}
			else {
				fa[f1] = f2;
				val[f1] = val[t2] - val[t1] + 1;
			}
		}
	}
	cout << (ans == 0 ? Q : ans) << endl;
	system("pause");
	return 0;
};