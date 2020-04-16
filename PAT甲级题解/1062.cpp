#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct  node
{
	int id;
	int vir, tal;
	int total;
	node(int a, int b, int c,int d) :id(a), vir(b), tal(c),total(d) {

	}
};
vector<node>v[4];
bool cmp1(node a, node b) {
	if (a.total != b.total)return a.total > b.total;
	else if (a.total == b.total&&a.vir != b.vir)return a.vir > b.vir;
	else return a.id < b.id;
}
int main() {
	int N, L, H;
	cin >> N >> L >> H;
	for (int i = 0; i < N; i++) {
		int t;
		int t1, t2;
		cin >> t >> t1 >> t2;
		if (t1 >= L && t2 >= L) {
			if (t1 >= H && t2 >= H)v[0].push_back(node(t, t1, t2, t1 + t2));
			else if (t1 >= H && t2 < H)v[1].push_back(node(t, t1, t2, t1 + t2));
			else if (t1 < H&&t2 < H&&t1 >= t2)v[2].push_back(node(t, t1, t2, t1 + t2));
			else v[3].push_back(node(t, t1, t2, t1 + t2));
		}
	}
	int num = 0;
	for (int i = 0; i < 4; i++) {
		sort(v[i].begin(), v[i].end(), cmp1);
		num += v[i].size();
	}
	printf("%d\n", num);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			printf("%08d", v[i][j].id);
			cout  << " " << v[i][j].vir << " " << v[i][j].tal << endl;
		}
	}
	system("pause");
	return 0;
}