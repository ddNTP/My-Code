#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int>tim;
int n, k;
map<string, bool>m;
map<string, vector<string>>v;
int num = 0;
int total = 0;
vector<string>tmp;
map<string, int>ans;
void dfs(string name) {
	m[name] = true;
	num++;
	tmp.push_back(name);
	total += tim[name];
	for (int i = 0; i < v[name].size(); i++) {
		string t = v[name][i];
		if (!m[t]) {
			dfs(t);
		}
	}
}
bool cmp1(string a,string b) {
	return tim[a] > tim[b];
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t;
		string s1,s2;
		cin >> s1 >> s2 >> t;
		tim[s1] += t;
		tim[s2] += t;
		v[s1].push_back(s2);
		v[s2].push_back(s1);
		m[s1] = false;
		m[s2] = false;
	}
	for (auto it = m.begin(); it != m.end();it++) {
		if (!it->second) 
			dfs(it->first);
		if (num >= 3 && total > k * 2) {
			sort(tmp.begin(), tmp.end(), cmp1);
			ans[tmp[0]] = num;
		}
		tmp.clear();
		total = 0;
		num = 0;
	}
	if (ans.size() == 0) {
		printf("0");
	}
	else {
		printf("%d\n", ans.size());
		for (auto it =ans.begin();it!=ans.end();it++)
			cout << it->first << " " << it->second << endl;
	}
	system("pause");
	return 0;
}