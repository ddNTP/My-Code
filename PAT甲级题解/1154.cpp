#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>v[10010];
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a[10010] = { -1 };
		int cnt = 0;
		unordered_map<int, bool>mp;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			if (!mp[a[j]]) {
				cnt++;
				mp[a[j]] = true;
			}
		}
		bool flag = true;
		for (int j = 0; j < n; j++) {
			for (int b = 0; b< v[j].size(); b++) {
				if (a[j] == a[v[j][b]]) {
					flag = false;
					break;
				}
			}
			if (!flag)break;
		}
		if (!flag) {
			printf("No\n");
			continue;
		}
		printf("%d-coloring\n", cnt);
	}
	system("pause");
	return 0;
}