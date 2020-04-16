#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>v[1010];
int n, L;
bool vis[1010];
struct node
{
	int index;
	int dep;
	node(int x, int y) :index(x), dep(y) {

	}
};
void bfs(int &num, int index) {
	queue<node>q;
	node a(index, 0);
	q.push(a);
	vis[a.index] = true;
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		int dep = t.dep + 1;
		for (int i = 0; i < v[t.index].size(); i++) {
			if (dep > L)break;
			if (!vis[v[t.index][i]]) {
				node x(v[t.index][i], dep);
				q.push(x);
				vis[x.index] = true;
				num++;
			}
		}
	}
}
int main() {
	cin >> n >> L;
	for (int i = 1; i <= n; i++) {
		int j;
		cin >> j;
		for (int k = 0; k < j; k++) {
			int t;
			cin >> t;
			v[t].push_back(i);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		fill(vis, vis + 1010, false);
		int num = 0;
		int q;
		cin >> q;
		bfs(num, q);
		printf("%d\n", num);
	}
	system("pause");
	return 0;
}