#include<iostream>
#include<string>
using namespace std;
struct node {
	string data;
	int l;
	int r;
}a[100];
string dfs(int root) {
	if (a[root].l == -1 && a[root].r == -1)return a[root].data;
	if (a[root].l == -1 && a[root].r != -1)return "(" + a[root].data + dfs(a[root].r) + ")";
	if (a[root].l != -1 && a[root].r != -1)return "(" + dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
}
int main() {
	int have[100] = {0};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1].data >> a[i + 1].l >> a[i + 1].r;
		if (a[i + 1].l != -1)have[a[i + 1].l] = 1;
		if (a[i + 1].r != -1)have[a[i + 1].r] = 1;
	}
	int root = 1;
	while (have[root] == 1)root++;
	string output=dfs(root);
	if (output[0] == '(')output = output.substr(1, output.length() - 2);
	cout << output;
	return 0;
}