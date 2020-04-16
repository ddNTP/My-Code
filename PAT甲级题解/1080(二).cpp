#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int ge, gi, id;
	double fin;
	int want[6], rank;
	bool operator<(const node &a)const {
		if (a.fin == fin)return ge > a.ge;
		return fin > a.fin;
	}
};
struct node1
{
	int id, i;
	node1(int x, int y) :id(x), i(y){}
	bool operator<(const node1&a)const {
		return id < a.id;
	}
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>sch(m);
	for (int i = 0; i < m; i++) 
		cin >> sch[i];
	vector<node>v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &v[i].ge, &v[i].gi);
		v[i].fin = (v[i].ge*1.0 + v[i].gi) / 2;
		v[i].id = i;
		for (int j = 0; j < k; j++)
			scanf("%d", &v[i].want[j]);
	}
	sort(v.begin(), v.end());
	v[0].rank = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].fin == v[i - 1].fin&&v[i].ge == v[i - 1].ge)v[i].rank = v[i - 1].rank;
		else v[i].rank = i + 1;
	}
	vector<node1>res[105];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int t = v[i].want[j];
			if (sch[t] > 0) {
				res[t].push_back(node1(v[i].id, i));
				sch[t]--;
				break;
			}
			if (v[i].rank == v[res[t].back().i].rank) {
				res[t].push_back(node1(v[i].id,i));
				break;
			}
		}
	}
	for (int i = 0; i < m; i++)
		sort(res[i].begin(), res[i].end());
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d", res[i][j].id);
			if (j != res[i].size() - 1)printf(" ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}