#include<iostream>
#include<vector>
#include<iostream>
#include<bitset>
using namespace std;
struct node {
	int v;
	int dis;
};
vector<node>v[201];
bitset<1000>b;
vector<int>a;
bool flag;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		v[t1].push_back(node{ t2,t3 });
		v[t2].push_back(node{ t1,t3 });
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		b.reset();
		a.clear();
		flag = false;
		for (int j = 0; j < c; c++) {
			int t;
			cin >> t;
			a.push_back(t);
			b[t] = 1;
		}
		int num = b.count();
		int dis = 0;
		for (int j = 0; j < a.size() - 1; j++) {
			int w = 0;
			for (; w < v[a[j]].size(); w++) {
				if (v[a[j]][w].v == a[j + 1]) {
					dis += v[a[j]][w].dis;
					break;
				}
			}
			if (w == v[a[j]].size()) {
				flag = true;
				break;
			}
		}
		if (flag) {
			printf("Path %d: NA (Not a TS cycle)\n", i + 1);
			continue;
		}
		if (num < n) {
			printf("Path %d: %d (Not a TS cycle)\n", i + 1, dis);
			continue;
		}
		if (num > n) {
			printf("Path %d: %d (TS cycle)\n", i + 1, dis);
			continue;
		}
		printf("Path %d: %d (TS simple cycle)\n", i + 1, dis);
	}
	return 0;
}