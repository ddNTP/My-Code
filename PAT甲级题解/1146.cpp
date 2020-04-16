#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>gra[1010];
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>v1(n + 1), v2(n + 1);
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v1[t2]++;
		gra[t1].push_back(t2);
	}
	int k;
	cin >> k;
	vector<int>ans;
	for (int i = 0; i < k; i++) {
		v2 = v1;
		bool flag = true;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			if (!flag)continue;
			if (v2[t] != 0) {
				flag = false;
				continue;
			}
			for (int q = 0; q < gra[t].size(); q++) {
				v2[gra[t][q]]--;
			}
		}
		if (!flag)ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
		if (i != ans.size() - 1)printf(" ");
	}
	system("pause");
	return 0;
}