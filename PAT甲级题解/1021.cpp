#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>v[10010];
bool vis[10010];
int maxdep = 0;
vector<int>dnum[10010];
void dfs(int index, int depth) {
	vis[index] = true;
	if (maxdep < depth)maxdep = depth;
	for (int i = 0; i < v[index].size(); i++) {
		if(vis[v[index][i]]==false)
			dfs(v[index][i], depth + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	int num = 1;
	for (int i = 1; i <= n; i++) {
		fill(vis + 1, vis + n + 1, false);
		dfs(i, 1);
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (vis[j] == false) {
				flag = false;
				num++;
				dfs(j, 1);
			}
		}
		if (flag) {
			dnum[maxdep].push_back(i);
		}
		else break;
		maxdep = 0;
	}
	int t = 0;
	for (int i=0; i < 10010; i++) {
		if (dnum[i].size() != 0)t = i;
	}
	if (num > 1)printf("Error: %d components", num);
	else {
		for (int i = 0; i < dnum[t].size(); i++) {
			printf("%d\n", dnum[t][i]);
		}
	}
	system("pause");
	return 0;
}