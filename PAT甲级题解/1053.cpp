#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<int>v[200];
int w[200];
ll s;
bool cmp1(int a, int b) {
	return w[a] > w[b];
}
vector<int>tmp;
void dfs(int index, int sum) {
	if (sum > s)return;
	if (index == 0) {
		tmp.push_back(w[index]);
		sum = sum + w[0];
	}
	if (v[index].size() == 0) {
		if (sum == s) {
			for (int i = 0; i < tmp.size(); i++) {
				if (i == 0)printf("%d", tmp[0]);
				else {
					printf(" %d", tmp[i]);
				}
				if (i == tmp.size() - 1)printf("\n");
			}
		}
		return;
	}
	for (int i = 0; i < v[index].size(); i++) {
		tmp.push_back(w[v[index][i]]);
		dfs(v[index][i], sum + w[v[index][i]]);
		tmp.pop_back();
	}
}
int main() {
	int n, m;
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < m; i++) {
		int cnt, id;
		cin >> id >> cnt;
		for (int i = 0; i < cnt; i++) {
			int c;
			cin >> c;
			v[id].push_back(c);
		}
	}
	for (int i = 0; i < n; i++)
		sort(v[i].begin(), v[i].end(), cmp1);
	dfs(0, 0);
	system("pause");
	return 0;
}