#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			v.push_back(t);
		}
		vector<int>tmp;
		tmp.push_back(v[0]);
		for (int i = 1; i < n; i++) {
			int j;
			for (j = 0; j < tmp.size(); j++) {
				if (tmp[j] >= v[i]) {
					tmp[j] = v[i];
					break;
				}
			}
			if (j == tmp.size())tmp.push_back(v[i]);
			else {
				int t = tmp[j];
				while (j >= 1 && tmp[j - 1] > t) {
					tmp[j] = tmp[j - 1];
					j--;
				}
				tmp[j] = t;
			}
		}
		cout << tmp.size() << endl;
	}
	system("pause");
	return 0;
}