#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
bool cmp1(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp1);
	int minn = min(v[v.size() - 1] - 1, n);
	if (minn < 0)minn = 0;
	int ans = 0;
	for (int i = minn; i <= n; i++) {
		int j;
		for (j = 0; j < n - i + 1; j++) {
			int k;
			for (k = j; k < j + i; k++) {
				if (v[k] > i)continue;
				else break;
			}
			if (k == j + i) {
				ans = i;
				break;
			}
			j = k;
		}
		if (j == n - i + 1)break;
	}
	printf("%d", ans);
	system("pause");
	return 0;
}