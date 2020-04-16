#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	map<int, int>mp;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		mp[t1]++;
		mp[t2]++;
	}
	vector<int>o, e, ans;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second % 2 == 0)e.push_back(it->first);
		else if (it->second % 2 == 1)o.push_back(it->first);
		ans.push_back(it->second);
	}
	bool flag = true;
	if (e.size() + o.size() < n) 
		flag = false;
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
		if (i != ans.size() - 1)printf(" ");
	} 

	if (flag&&o.size() == 0)
		printf("\nEulerian");
	else if (flag&&o.size() == 2)
		printf("\nSemi-Eulerian");
	else
		printf("\nNon-Eulerian");
	system("pause");
	return 0;
}