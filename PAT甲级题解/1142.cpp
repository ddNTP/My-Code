#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int, bool>m;
vector<int>gra[210];
bool have[210];
int main() {
	int nv, ne;
	cin >> nv >> ne;
	for (int i = 0; i < ne; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		gra[t1].push_back(t2);
		gra[t2].push_back(t1);
		m[t1 * 1000 + t2] = true;
		m[t2 * 1000 + t1] = true;
	}
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		fill(have+1, have + nv + 1, false);
		int b;
		cin >> b;
		vector<int>tmp;
		bool flag = true;
		for (int j = 0; j < b; j++) {
			int t;
			cin >> t;
			tmp.push_back(t);
			have[t] = true;
		}
		for (int k = 0; k < tmp.size() - 1; k++) {
			if (!flag)break;
			for (int c = k + 1; c < tmp.size(); c++) {
				if (!m[tmp[k] * 1000 + tmp[c]]) {
					flag = false;
					break;
				}
			}
		}
		if (!flag) {
			printf("Not a Clique\n");
			continue;
		}
		vector<int>tmp1;
		for (int j = 0; j < gra[tmp[0]].size(); j++) {
			int k = gra[tmp[0]][j];
			if (!have[k]) {
				tmp1.push_back(k);
			}
		}
		for (int j = 0; j < tmp1.size(); j++) {
			for (int k = 0; k < tmp.size(); k++) {
				if (!m[tmp1[j] * 1000 + tmp[k]])break;
				if (k == tmp.size()-1) {
					flag = false;
					break;
				}
			}
			
		}
		if (flag)printf("Yes\n");
		else printf("Not Maximal\n");
	}
	system("pause");
	return 0;
}