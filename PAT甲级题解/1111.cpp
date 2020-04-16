#include<iostream>
#include<vector>
using namespace std;
int lenthgra[510][510];
int timegra[510][510];
int n, m;
int src, des;
bool vis[510];
int d[510];
const int inf = 0x3fffffff;
vector<int>pre[510];
void dijkstra(int gra[][510]){
	fill(vis, vis + 510, false);
	fill(d, d + 510, inf);
	for (int i = 0; i < 510; i++)pre[i].clear();
	d[src] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, min = inf;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && min > d[j]) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int j = 0; j < n; j++) {
			if (!vis[j]) {
				if (gra[u][j] + d[u] < d[j]) {
					d[j] = gra[u][j] + d[u];
					pre[j].clear();
					pre[j].push_back(u);
				}
				else if (gra[u][j] + d[u] == d[j]){
					pre[j].push_back(u);
				}
			}
		}
	}
}
vector<int>tmp, ans;
int totaltime = inf;
void dfs(int index) {
	if (index == src) {
		tmp.push_back(src);
		int tmptotal = 0;
		for (int i=tmp.size()-1; i >0; i--) {
			tmptotal += timegra[tmp[i]][tmp[i - 1]];
		}
		if (tmptotal < totaltime) {
			ans = tmp;
			totaltime = tmptotal;//
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(index);
	for (int i = 0; i < pre[index].size(); i++) {
		dfs(pre[index][i]);
	}
	tmp.pop_back();
}
int minn = inf;
vector<int>ans1;
void dfs1(int index) {
	if (index == src) {
		tmp.push_back(src);
		if (tmp.size() < minn) {
			ans1 = tmp;
			minn = ans1.size();
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(index);
	for (int i = 0; i < pre[index].size(); i++) {
		dfs1(pre[index][i]);//
	}
	tmp.pop_back();
}
int main() {
	cin >> n >> m;
	fill(lenthgra[0], lenthgra[0] + 510 * 510, inf);//
	fill(timegra[0], timegra[0] + 510 * 510, inf);//
	for (int i = 0; i < m; i++) {
		int t1, t2, t3, t4, t5;
		cin >> t1 >> t2 >> t3 >> t4 >> t5;
		if (t3) {
			lenthgra[t1][t2] = t4;
			timegra[t1][t2] = t5;
		}
		else {
			lenthgra[t1][t2] = lenthgra[t2][t1] = t4;
			timegra[t1][t2] = timegra[t2][t1] = t5;
		}
	}
	cin >> src >> des;
	dijkstra(lenthgra);
	int distance = d[des];
	dfs(des);
	tmp.clear();
	dijkstra(timegra);
	int tim = d[des];
	dfs1(des);
	if (ans == ans1) {
		printf("Distance = %d; Time = %d: ", distance, tim);
		for (int i = ans.size()-1; i >=0; i--) {
			printf("%d", ans[i]);
			if (i != 0)printf(" -> ");
		}
	}
	else {
		printf("Distance = %d: ", distance);
		for (int i = ans.size() - 1; i >= 0; i--) {
			printf("%d", ans[i]);
			if (i != 0) printf(" -> ");
		}
		cout << endl;
		printf("Time = %d: ", tim);
		for (int i = ans1.size() - 1; i >= 0; i--) {
			printf("%d", ans1[i]);
			if (i != 0)printf(" -> ");
		}
	}
	system("pause");
	return 0;
}