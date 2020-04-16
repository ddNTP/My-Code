#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1005;
struct Node
{
	int x, y;
}node[N];
double g[N][N];
int valid[N];
double getdis(Node a, Node b) {
	int x = a.x - b.x;
	int y = a.y - b.y;
	return pow(x*x + y * y, 0.5);
}
int fa[N];
int findfa(int x) {
	int z = x;
	while (fa[x] != x)x = fa[x];
	while (fa[z] != z) {
		int y = fa[z];
		fa[z] = x;
		z = y;
	}
	return x;
}
void unio(int x, int y) {
	int fax = findfa(x);
	int fay = findfa(y);
	if (fax != fay) 
		fa[fax] = fay;
}
int main() {
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= n; i++) 
		cin >> node[i].x >> node[i].y;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			g[i][j] = g[j][i] = getdis(node[i], node[j]);
		}
	}
	char c;
	getchar();
	while (scanf("%c", &c) != EOF) {
		if (c == 'S') {
			int t1, t2;
			cin >> t1 >> t2;
			if (findfa(t1) == findfa(t2)) {
				cout << "SUCCESS\n";
			}
			else
				cout << "FAIL\n";
		}
		else {
			int t;
			cin >> t;
			valid[t] = 1;
			for (int i = 1; i <= n; i++) {
				if (valid[i]&&g[i][t] <= d && findfa(i) != findfa(t)) {
					unio(i, t);
				}
			}
		}
		getchar();
	}
	system("pause");
	return 0;
}