#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		unordered_set <int>set;
		vector<int>v;
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			set.insert(t);
			v.push_back(t);
		}
		if (set.size() != m) {
			printf("NO\n");
			continue;
		}
		bool flag = false;
		for (int j = 0; j < m - 1; j++) {
			for (int k = j + 1; k < m; k++) {
				if (abs(v[k] - v[j]) == abs(k - j)) {
					flag = true;
					break;
				}
			}
			if (flag)break;
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