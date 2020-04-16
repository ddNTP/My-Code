#include<iostream>
#include<vector>
using namespace std;
vector<int>gra[510];
bool vis[510];
void dfs(int index) {
	vis[index] = true;
	for (int i = 0; i < gra[index].size(); i++) {
		if (!vis[gra[index][i]]) {
			dfs(gra[index][i]);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		gra[t1].push_back(t2);
		gra[t2].push_back(t1);
	}
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (gra[i].size() % 2 == 1) 
			num++;
		printf("%d", gra[i].size());
		if (i != n)printf(" ");
	}
	dfs(1);
	bool flag = true;
	for (int i = 1; i <= n; i++) 
		if (!vis[i])flag = false;
	cout << endl;
	if (num == 0 && flag)printf("Eulerian");
	else if (num == 2 && flag)printf("Semi-Eulerian");
	else {
		printf("Non-Eulerian");
	}
	system("pause");
	return 0;
}