#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;
map<string, int>online, mid, fina;
vector<string>tmp;
map<string, bool>have;
struct node
{
	string name;
	int mid, fina, online;
	int finalgrade;
};
bool cmp(node a,node b) {
	if (a.finalgrade != b.finalgrade)
		return a.finalgrade > b.finalgrade;
	else return a.name < b.name;
}
int main() {
	int p, m, n;
	cin >> p >> m >> n;
	for (int i = 0; i < p; i++) {
		string s;
		int t;
		cin >> s >> t;
		online[s] = t;
		if (t >= 200)tmp.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		string s;
		int t;
		cin >> s >> t;
		mid[s] = t;
		have[s] = true;
	}
	for (int i = 0; i < n; i++) {
		string s;
		int t;
		cin >> s >> t;
		fina[s] = t;
	}
	vector<node>ans;
	for (int i = 0; i < tmp.size(); i++) {
		int a = 0;
		if (fina[tmp[i]] >= mid[tmp[i]])a = fina[tmp[i]];
		else 
			a = int(0.4*mid[tmp[i]] + 0.6*fina[tmp[i]] + 0.5);
		if (a >= 60) {
			node c;
			c.fina = fina[tmp[i]];
			c.finalgrade = a;
			if(have[tmp[i]])c.mid = mid[tmp[i]];
			else c.mid = -1;
			c.name = tmp[i];
			c.online = online[tmp[i]];
			ans.push_back(c);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i].name << " " << ans[i].online << " " << ans[i].mid << " " << ans[i].fina << " " << ans[i].finalgrade << endl;
	system("pause");
	return 0;
}