#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct  node
{
	int id, fa, mo, esta, arae;
	vector<int>child;
}member[10000];
struct node1
{
	int id, num;
	double ave1, ave2;
};
int fa[10000];
vector<int>v;
void init() {
	for (int i = 0; i < 10000; i++) {
		member[i].id = i;
		member[i].fa = -1;
		member[i].mo = -1;
		member[i].esta = 0;
		member[i].arae = 0;
		fa[i] = i;
	}
}
int findfa(int a) {
	int x = a;
	while (fa[x] != x) {
		x = fa[x];
	}
	int z;
	while (fa[a] != a) {
		z = a;
		a = fa[a];
		fa[z] = x;
	}
	return a;
}
void unio(int a,int b) {
	int faa = findfa(a);
	int fab = findfa(b);
	if (faa != fab) {
		if (faa < fab)fa[fab] = faa;
		else fa[faa] = fab;
	}
}
bool isroot[10000];
int cnt[10000];
int cnt1[10000];
int cnt2[10000];
bool cmp1(node1 a,node1 b) {
	if (a.ave2 != b.ave2)return a.ave2 > b.ave2;
	else return a.id < b.id;
}
int main() {
	init();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t[7];
		cin >> t[0] >> t[1] >> t[2] >> t[3];
		v.push_back(t[0]);
		member[t[0]].fa = t[1];
		member[t[0]].mo = t[2];
		if (t[1] != -1) {
			unio(t[0], t[1]);
			member[t[1]].child.push_back(t[0]);
		}
		if (t[2] != -1) {
			unio(t[0], t[2]);
			member[t[2]].child.push_back(t[0]);
		}
		for (int j = 0; j < t[3]; j++) {
			cin >> t[4];
			member[t[0]].child.push_back(t[4]);
			unio(t[0], t[4]);
		}
		cin >> t[5] >> t[6];
		member[t[0]].esta = t[5];
		member[t[0]].arae = t[6];
	}
	for (int i = 0; i < v.size(); i++) {
		int t = findfa(v[i]);
		isroot[t] = true;
	}
	for (int i = 0; i < 10000; i++) {
		int t = findfa(i);
		if (isroot[t]) {
			cnt[t]++;
			cnt1[t] += member[i].esta;
			cnt2[t] += member[i].arae;
		}
	}
	vector<node1>v1;
	for (int i = 0; i < 10000; i++) {
		if (isroot[i]) {
			node1 a;
			a.id = i;
			a.num = cnt[i];
			a.ave1 = cnt1[i] * 1.0 / a.num;
			a.ave2 = cnt2[i] * 1.0 / a.num;
			v1.push_back(a);
		}
	}
	sort(v1.begin(), v1.end(), cmp1);
	printf("%d\n", v1.size());
	for (int i = 0; i < v1.size(); i++) 
		printf("%04d %d %.3f %.3f\n", v1[i].id, v1[i].num, v1[i].ave1, v1[i].ave2);
	system("pause");
	return 0;
}