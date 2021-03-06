#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N = 2005;
char s[N][8];
int fa[N];
int findfa(int x) {
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}
struct edge
{
	int u, v, w;
	edge(int x,int y,int z):u(x),v(y),w(z){}
	bool operator<(const edge&a)const {
		return w > a.w;
	}
};
int getdis(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 7; i++)
		if (s[x][i] != s[y][i])cnt++;
	return cnt;
}
int main() {
	int n;
	while (cin >> n) {
		if (n == 0)break;
		for (int i = 0; i <= n; i++)
			fa[i] = i;
		for (int i = 0; i < n; i++)
			scanf("%s", s[i]);
		priority_queue<edge>q;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				q.push(edge(i, j, getdis(i, j)));
		int cnt = 0, ans = 0;
		while (!q.empty() && cnt != n - 1) {
			edge e = q.top();
			q.pop();
			int u = e.u, v = e.v, w = e.w;
			int f1 = findfa(u), f2 = findfa(v);
			if (f1 != f2) {
				fa[f1] = f2;
				cnt++;
				ans += w;
			}
		}
		printf("The highest possible quality is 1/%d.\n", ans);
		
	}
	system("pause");
	return 0;
}