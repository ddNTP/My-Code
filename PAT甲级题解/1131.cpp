#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int, int>line;
vector<int>gra[10010];
int start, ed;
vector<int>ans, tmp;
const int inf = 99999;
int minsta = inf, mintransfer = inf;
bool vis[10010];
int mintran(vector<int>a) {
	int num = 0;
	int tmpline = line[a[0] * 10000 + a[1]];
	for (int i = 1; i < a.size() - 1; i++) {
		if (line[a[i] * 10000 + a[i + 1]] != tmpline)num++;
		tmpline = line[a[i] * 10000 + a[i + 1]];
	}
	return num;
}
void dfs(int index) {
	if (index == ed) {
		tmp.push_back(index);
		if (tmp.size()-1 < minsta) {
			ans = tmp;
			minsta = tmp.size() - 1;
			mintransfer = mintran(tmp);
		}
		else if (tmp.size() - 1 == minsta && mintran(tmp) < mintransfer) {
			ans = tmp;
			mintransfer = mintran(tmp);
		}
		tmp.pop_back();
	}
	tmp.push_back(index);
	vis[index] = true;
	for (int i = 0; i < gra[index].size(); i++) {
		int t = gra[index][i];
		if (!vis[t])
			dfs(t);
	}
	tmp.pop_back();
	vis[index] = false;
}
int main() {
	int n, m, k;
	cin>>n;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> m >> t1;
		for (int j = 1; j < m; j++) {
			cin >> t2;
			gra[t1].push_back(t2);
			gra[t2].push_back(t1);
			line[t1 * 10000 + t2] = i + 1;
			line[t2 * 10000 + t1] = i + 1;
			t1 = t2;
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		fill(vis, vis + 10010, false);
		minsta = inf, mintransfer = inf;
		cin >> start >> ed;
		dfs(start);
		printf("%d\n", minsta);
		int linen = line[ans[0] * 10000 + ans[1]];
		int pre = ans[0];
		for (int j = 1; j < ans.size() - 1; j++) {
			if (linen == line[ans[j] * 10000 + ans[j + 1]]) continue;
			printf("Take Line#%d from %04d to %04d.\n", linen, pre, ans[j]);
			pre = ans[j];
			linen = line[ans[j] * 10000 + ans[j + 1]];
		}
		printf("Take Line#%d from %04d to %04d.\n", linen, pre, ed);
	}
	system("pause");
	return 0;
}