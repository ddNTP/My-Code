#include<iostream>
#include<algorithm>
using namespace std;
int fa[1010];
int course[1010] = { 0 };
int isroot[1010] = { 0 };
bool cmp1(int a, int b) {
	return a > b;
}
void init(int n) {
	for (int i = 1; i <= n; i++) 
		fa[i] = i;
}
int findfa(int x) {
	int a = x;
	while (x != fa[x])
		x = fa[x];
	while (a != fa[a]) {
		int z = a;
		a = fa[a];
		fa[z] = x;
	}
	return x;
}
void unio(int a,int b) {
	int faa = findfa(a);
	int fab = findfa(b);
	if (faa != fab) {
		fa[fab] = faa;
	}
}
int main() {
	int n;
	cin >> n;
	init(n);
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		getchar();
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			if (course[t] == 0)course[t] = i;
			unio(i, findfa(course[t]));
		}
	}
	int num = 0;
	for (int i = 1; i <= n; i++)
		isroot[findfa(i)]++;
	sort(isroot, isroot + 1010, cmp1);
	for (int i = 0; i < 1010; i++) {
		if (isroot[i] != 0)num++;
	}
	printf("%d\n", num);
	for (int i = 0; i < num; i++) {
		printf("%d", isroot[i]);
		if (i != num - 1)printf(" ");
	}
	system("pause");
	return 0;
}