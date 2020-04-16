#include<iostream>
#include<set>
using namespace std;
set<int>s[100];
int main() {
	int n,m,t,k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			s[i].insert(t);
		}
	}
	scanf("%d", &k);
	int a, b;
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &a, &b);
		int sum, com=0;
		for (auto it = s[a].begin(); it != s[a].end(); it++) {
			if (s[b].find(*it) != s[b].end())com++;
		}
		sum = s[a].size() + s[b].size() - com;
		double perc;
		perc = com*1.0 / sum * 1.0 * 100;
		printf("%.1f%%\n", perc);
	}
	system("pause");
	return 0;
}