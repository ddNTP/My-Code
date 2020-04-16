#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
	int d, n;
	cin >> d >> n;
	vector<int>v, tmp;
	v.push_back(d);
	while (--n) {
		unordered_map<int, int>m;
		tmp.clear();
		for (int i = 0; i < v.size(); i++) {
			int cnt = 1;
			int j;
			for ( j = i + 1; j < v.size(); j++) {
				if (v[j] == v[i])cnt++;
				else break;
			}
			tmp.push_back(v[i]);
			tmp.push_back(cnt);
			i = j - 1;
		}
		v = tmp;
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
	}
	system("pause");
}