#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int u, v;
};
vector<node>v;
bool have[10010];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		node a;
		a.u = t1;
		a.v = t2;
		v.push_back(a);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int kn;
		cin >> kn;
		fill(have, have + n, false);
		for (int j = 0; j < kn; j++) {
			int t;
			cin >> t;
			have[t] = true;
		}
		bool flag = false;
		for (int w = 0; w < v.size(); w++) {
			if (have[v[w].u] || have[v[w].v])continue;
			else {
				flag = true;
				break;
			}
		}
		if (flag)printf("No\n");
		else printf("Yes\n");
		
	}
	system("pause");
	return 0;
}