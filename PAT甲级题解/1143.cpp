#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int, bool>have;
int main() {
	int m, n;
	cin >> m >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		have[v[i]] = true;
	}
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		if (!have[t1] && !have[t2]) {
			printf("ERROR: %d and %d are not found.\n", t1, t2);
			continue;
		}
		if (!have[t1] || !have[t2]) {
			printf("ERROR: %d is not found.\n", !have[t1] ? t1 : t2);
			continue;
		}
		int j;
		for (j = 0; j < n; j++) {
			if ((v[j] >= t1 && v[j] <= t2) || (v[j] <= t1 && v[j] >= t2)) {
				break;
			}
		}
		if (v[j] == t1 ) {
			printf("%d is an ancestor of %d.\n", t1, t2);
			continue;
		}
		if (v[j] == t2) {
			printf("%d is an ancestor of %d.\n", t2, t1);
			continue;
		}
		printf("LCA of %d and %d is %d.\n", t1, t2, v[j]);
	}
	system("pause");
	return 0;
}