#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int cap[3];
struct node
{
	int v[3];
	int step;
	node(int t1, int t2, int t3, int t4) {
		v[0] = t1;
		v[1] = t2;
		v[2] = t3;
		step = t4;
	}
};
int ans;
int vis[105][105][105];
int ds[6] = { 0,0,1,1,2,2 };
int dd[6] = { 1,2,0,2,0,1 };
void bfs() {
	queue<node>q;
	memset(vis, 0, sizeof(vis));
	q.push(node(cap[0], 0, 0, 0));
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 3; i++)
			if (t.v[i] == ans)cnt++;
		if (cnt == 2) {
			cout << t.step << endl;
			return;
		}
		for (int i = 0; i < 6; i++) {
			node tt = t;
			tt.step++;
			int tmp = tt.v[ds[i]] + tt.v[dd[i]];
			if (tmp > cap[dd[i]]) {
				tt.v[dd[i]] = cap[dd[i]];
				tt.v[ds[i]] = tmp - tt.v[dd[i]];
			}
			else {
				tt.v[dd[i]] = tmp;
				tt.v[ds[i]] = 0;
			}
			if (!vis[tt.v[0]][tt.v[1]][tt.v[2]]) {
				q.push(tt);
				vis[tt.v[0]][tt.v[1]][tt.v[2]] = 1;
			}
		}
	}
	printf("NO\n");
}
int main() {
	cin >> cap[0] >> cap[1] >> cap[2];
	while (cap[0] != 0) {
		
		if (cap[0] % 2 == 0) {
			ans = cap[0] / 2;
			bfs();
		}
		else
			printf("NO\n");
		cin >> cap[0] >> cap[1] >> cap[2];
	}
	system("pause");
	return 0;
}