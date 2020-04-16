#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map <string, vector<string>>v;
unordered_map <string, bool>fri;
struct node
{
	int u, v;
};
bool cmp(node a, node b) {
	return a.u != b.u ? abs(a.u) < abs(b.u) : abs(a.v) < abs(b.v);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
		fri[t1 + t2] = true;
		fri[t2 + t1] = true;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		vector<node>ans;
		vector<string>tmp1, tmp2;
		string t1, t2;
		cin >> t1 >> t2;
		for (int j = 0; j < v[t1].size(); j++) {
			if (v[t1][j] == t2)continue;
			if (v[t1][j].size()==t1.size())tmp1.push_back(v[t1][j]);
		}
		for (int j = 0; j < v[t2].size(); j++) {
			if (v[t2][j] == t1)continue;
			if (t2.size() ==v[t2][j].size())tmp2.push_back(v[t2][j]);
		}
		for (int j = 0; j < tmp1.size(); j++) {
			for (int a = 0; a < tmp2.size(); a++) {
				if (fri[tmp1[j]+tmp2[a]]) {
					ans.push_back(node{ stoi(tmp1[j]),stoi(tmp2[a]) });
				}
			}
		}
		printf("%d\n", ans.size());
		sort(ans.begin(), ans.end(), cmp);
		for (int j = 0; j < ans.size(); j++) {
			printf("%04d %04d\n", abs(ans[j].u), abs(ans[j].v));
		}
	}
	return 0;
}