#include<iostream>
#include<vector>
using namespace std;
bool gra[210][210];
bool have[210];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		gra[t1][t2] = gra[t2][t1] = true;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		if (t != n + 1) {
			for (int j = 0; j < t; j++) {
				int t1;
				cin >> t1;
			}
			printf("NO\n");
			continue;
		}
		vector<int>v;
		for (int j = 0; j < t; j++) {
			int t1;
			cin >> t1;
			v.push_back(t1);
		}
		if (v[0] != v[v.size() - 1]) {
			printf("NO\n");
			continue;
		}
		fill(have + 1, have + n + 1, false);
		bool flag = false;
		for (int j = 0; j < v.size() - 1; j++) {
			if (gra[v[j]][v[j + 1]]) {
				have[v[j]] = true;
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag) {
			printf("NO\n");
			continue;
		}
		for (int j = 1; j <= n; j++) {
			if (!have[j]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	system("pause");
	return 0;
}