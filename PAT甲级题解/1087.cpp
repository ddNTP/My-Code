#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int n, k;
string s;
map<string, int>hap;
struct node
{
	string name;
	int cost;
	node(string na, int co) :name(na), cost(co) {

	}
};
map<string, vector<node>>gra;
map<string, bool>vis;
map<string, int>dis;
map<string, vector<node>>pre;
const int inf = 0x3fffffff;
void dijkstra() {
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int min = inf;
		string u = "";
		for (auto it = dis.begin(); it != dis.end(); it++) {
			if (!vis[it->first]&&it->second < min) {
				min = it->second;
				u = it->first;
			}
		}
		if (min == inf)return;
		vis[u] = true;
		for (int j = 0; j < gra[u].size(); j++) {
			node t = gra[u][j];
			if (!vis[t.name]) {
				if (dis[u] + t.cost < dis[t.name]) {
					pre[t.name].clear();
					dis[t.name] = dis[u] + t.cost;
					node a(u, t.cost);
					pre[t.name].push_back(a);
				}
				else if (dis[u] + t.cost == dis[t.name]) {
					node a(u, t.cost);
					pre[t.name].push_back(a);
				}
			}
		}
	}
}
int totalnum = 0;
vector<string>ans, tmp;
int maxhap = 0;
int ave = 0;
void dfs(string str) {
	if (str == s) {
		totalnum++;
		int total = 0;
		int tmpmax = 0;
		for (int i = 0; i < tmp.size(); i++)
			total += hap[tmp[i]];
		int tmpave = total / tmp.size();
		tmp.push_back(s);
		if (total > maxhap) {
			ans = tmp;
			maxhap = total;
			ave = tmpave;
		}
		else if (total == maxhap && ave < tmpave) {
			ans = tmp;
			maxhap = total;
			ave = tmpave;
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(str);
	for (int i = 0; i < pre[str].size(); i++) {
		dfs(pre[str][i].name);
	}
	tmp.pop_back();
}
int main() {
	cin >> n >> k >> s;
	for (int i = 0; i < n - 1; i++) {
		string t;
		int t1;
		cin >> t >> t1;
		hap[t] = t1;
	}
	for (int i = 0; i < k; i++) {
		string t1, t2;
		int cost;
		cin >> t1 >> t2 >> cost;
		vis[t1] = false;
		vis[t2] = false;
		dis[t1] = inf;
		dis[t2] = inf;
		node a(t1, cost);
		node b(t2, cost);
		gra[t1].push_back(b);
		gra[t2].push_back(a);
	}
	dijkstra();
	dfs("ROM");
	printf("%d %d %d %d\n", totalnum, dis["ROM"], maxhap, ave);
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
		if (i != 0)printf("->");
	}
	system("pause");
	return 0;
}