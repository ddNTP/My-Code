#include<iostream>
using namespace std;
int inf = 9999999;
bool vis[1010];
int arc[1010][1010] = { inf };
int check[1010];
int n, m, k;
void dfs(int index) {
	vis[index] = true;
	for (int i = 1; i <= n; i++) {
		if (arc[index][i] == 1) {
			if (!vis[i]) {
				
				dfs(i);
			}

		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		arc[t1][t2] = arc[t2][t1] = 1;
	}
	for (int i = 0; i < k; i++)
		cin >> check[i];
	for (int i = 0; i < k; i++) {
		for (int j = 1; j <=n; j++)
			vis[j] = false;
		vis[check[i]] = true;
		int num = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j] == false) {
				num++;
				dfs(j);
			}
		}
		printf("%d\n", num-1);
	}
	system("pause");
	return 0;
}