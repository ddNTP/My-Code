#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;
struct node {
	int a, b;
};
bool cmp(node &a, node &b) {
	if (a.a != b.a)return a.a < b.a;
	else return a.b < b.b;
}
int main() {
	int n, m, k;
	cin >> n >> m;
	unordered_map<int, multiset<int>>mp;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		mp[t1].insert(t2);
		mp[t2].insert(t1);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		vector<int>v1, v2;
		vector<node>ans;
		for (int x : mp[t1])
			if (t1*x > 0) v1.push_back(x);
		for (int x : mp[t2])
			if (t2*x > 0) v2.push_back(x);
		for (int x : v1)
			for (int y : v2)
				if (mp[x].find(y) != mp[x].end())
					ans.push_back(node{ x,y });
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", ans.size());
		for (auto x : ans)
			printf("%04d %04d\n", x.a, x.b);
	}
	system("pause");
	return 0;
}