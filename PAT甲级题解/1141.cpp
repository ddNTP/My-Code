#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
struct  node
{
	string id;
	int grade;
};
struct node1
{
	string scl;
	int rank, total, num;
};
bool cmp(node1 a, node1 b) {
	if (a.total != b.total)return a.total > b.total;
	else if (a.total == b.total&&a.num != b.num)return a.num < b.num;
	else return a.scl < b.scl;
}
int main() {
	int n;
	cin >> n;
	map<string, vector<node>>m;
	vector<node1>ans;
	for (int i = 0; i < n; i++) {
		string id, scl;
		int grade;
		cin >> id >> grade >> scl;
		node a;
		a.id = id;
		a.grade = grade;
		for (int j = 0; j < scl.size(); j++) {
			scl[j] = tolower(scl[j]);
		}
		m[scl].push_back(a);
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		vector<node>v = it->second;
		double t = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].id[0] == 'B')t += v[i].grade / 1.5;
			else if (v[i].id[0] == 'A')t += v[i].grade;
			else t += v[i].grade*1.5;
		}
		int total = (int)t;
		ans.push_back(node1{ it->first,0,total,(int)v.size() });
	}
	sort(ans.begin(), ans.end(), cmp);
	ans[0].rank = 1;
	for (int i = 1; i < ans.size(); i++) {
		if (ans[i].total == ans[i - 1].total)ans[i].rank = ans[i - 1].rank;
		else ans[i].rank = i + 1;
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) 
		printf("%d %s %d %d\n", ans[i].rank, ans[i].scl.c_str(), ans[i].total, ans[i].num);
	system("pause");
	return 0;
}