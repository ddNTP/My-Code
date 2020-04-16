#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using	namespace std;
struct node
{
	int v;
	double r, c;
	node(int x,double y,double z):v(x),r(y),c(z){}
};
int N, M, S;
double V;
vector<node>v[105];
double d[105];
int cnt[105];
int vis[105];
bool spfa() {
	d[S] = V;
	queue<int>q;
	q.push(S);
	vis[S] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		vis[t] = 0;
		for (int i = 0; i < v[t].size(); i++) {
			node e = v[t][i];
			double x = (d[t] - e.c)*e.r;
			if (x - d[e.v] > 1e-8) {
				d[e.v] = x;
				if (vis[e.v])continue;
				q.push(e.v);
				vis[e.v] = 1;
				cnt[e.v]++;
				if (cnt[e.v] > N)return true;
			}
		}
	}
	return false;
}
int main() {
	cin >> N >> M >> S >> V;	
	for (int i = 0; i < M; i++) {
		int t1, t2;
		double t3, t4, t5, t6;
		scanf("%d %d %lf %lf %lf %lf", &t1, &t2, &t3, &t4, &t5, &t6);
		v[t1].push_back(node(t2, t3, t4));
		v[t2].push_back(node(t1, t5, t6));
	}
	if (spfa())printf("YES\n");
	else printf("NO\n");
	system("pause");
	return 0;
}