#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool have[100010];
int main() {
	int n;
	cin >> n;
	map<int, int>m;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		m[t1] = t2;
		m[t2] = t1;
	}
	int k;
	cin >> k;
	vector<int>ans, tmp;
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		have[t] = true;
		tmp.push_back(t);
	}
	for (int i = 0; i < tmp.size(); i++) {
		if (m.find(tmp[i]) != m.end()) {
			if (have[m[tmp[i]]])continue;
			else ans.push_back(tmp[i]);
		}
		else ans.push_back(tmp[i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%05d", ans[i]);
		if (i != ans.size() - 1)printf(" ");
	}
	system("pause");
	return 0;
}