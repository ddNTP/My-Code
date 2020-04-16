#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int, int>mp;
int main() {
	int n, m;
	cin >> n >> m;
	int mindis = 99999999;
	int minindex = 1;
	for (int i = 0; i < m; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >>t3;
		mp[t1 * 200 + t2] = t3;
		mp[t2 * 200 + t1] = t3;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		vector<int>v;
		unordered_map<int, bool>have;
		for (int j = 0; j < a; j++) {
			int t;
			cin >> t;
			have[t] = true;
			v.push_back(t);
		}
		int total = 0;
		bool flag = true;
		for (int j = 0; j < a - 1; j++) {
			if (mp[v[j] * 200 + v[j + 1]] == 0) {
				flag = false;
				break;
			}
			else total += mp[v[j] * 200 + v[j + 1]];
		}
		if (!flag) {
			printf("Path %d: NA (Not a TS cycle)\n", i + 1);
			continue;
		}
		for (int j = 1; j <= n; j++) {
			if (!have[j]) {
				flag = false;
				break;
			}
		}
		if (v[0] != v[a - 1])flag = false;
		if (!flag) {
			printf("Path %d: %d (Not a TS cycle)\n", i + 1, total);
			continue;
		}
		if (a == n + 1) {
			printf("Path %d: %d (TS simple cycle)\n", i + 1, total);
			if (total < mindis) {
				mindis = total;
				minindex = i + 1;
			}
			continue;
		}
		else {
			printf("Path %d: %d (TS cycle)\n", i + 1, total);
			if (total < mindis) {
				mindis = total;
				minindex = i + 1;
			}
			continue;
		}
	}
	printf("Shortest Dist(%d) = %d", minindex, mindis);
	system("pause");
	return 0;
}