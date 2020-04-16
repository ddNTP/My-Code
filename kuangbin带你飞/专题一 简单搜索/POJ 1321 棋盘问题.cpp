#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
char board[9][9];
int col[9];
int n;
int res;
void dfs(int dep, int k) {
	if (k == 0) {
		res++;
		return;
	}
	if (dep == n)return;
	for (int i = 0; i < n; i++) {
		if (!col[i] && board[dep][i] == '#') {
			col[i] = 1;
			dfs(dep + 1, k - 1);
			col[i] = 0;
		}
	}
	dfs(dep + 1, k);
}
int main() {
	int k;
	cin >> n >> k;
	while (n != -1 && k != -1) {
		res = 0;
		for (int i = 0; i < n; i++)
				scanf("%s", board[i]);
		dfs(0, k);
		cout << res << endl;
		cin >> n >> k;
	}
	return 0;
}