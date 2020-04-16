#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>ans;
int times[50010];
bool cmp(int a, int b) {
	if (times[a] != times[b]) {
		return times[a] > times[b];
	}
	else return a < b;
}

int main() {
	int n, k;
	cin >> n >> k;
	int maxn = 0;
	int a;
	cin >> a;
	ans.push_back(a);
	times[a]++;
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		int num = 0;
		printf("%d:", t);
		if (ans.size() < k) {
			bool flag = true;
			for (int j = 0; j < ans.size(); j++) {
				printf(" %d", ans[j]);
				if (ans[j] == t)flag = false;
			}
			if(flag)ans.push_back(t);
			times[t]++;
			sort(ans.begin(), ans.end(), cmp);
			cout << endl;
		}
		else {
			bool flag = true;
			for (int j = 0; j < ans.size(); j++) {
				printf(" %d", ans[j]);
				if (ans[j] == t)flag = false;
			}
			times[t]++;
			if (flag) {
				if (times[t] > times[ans[k - 1]])
					ans[k - 1] = t;
				else if (times[t] == times[ans[k - 1]] && t < ans[k - 1])
					ans[k - 1] = t;
			}
			sort(ans.begin(), ans.end(), cmp);
			cout << endl;
		}
	}
	system("pause");
	return 0;
}