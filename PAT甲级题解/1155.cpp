#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
int n;
vector<int>tmp;
bool flag = true;
bool flag1;
void dfs1(int index) {
	if (index > n)return;
	if (index != 1&&flag1) {
		if (v[index - 1] > v[index / 2 - 1])flag = false;
	}
	else if (index != 1 && !flag1) {
		if (v[index - 1] < v[index / 2 - 1])flag = false;
	}
	tmp.push_back(v[index - 1]);
	if (index * 2 > n) {
		for (int i = 0; i < tmp.size(); i++) {
			printf("%d", tmp[i]);
			if (i != tmp.size() - 1)printf(" ");
		}
		printf("\n");
	}
	dfs1(index * 2 + 1);
	dfs1(index * 2);
	tmp.pop_back();
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	if (v[0] > v[n - 1]) {
		flag1 = true;
		dfs1(1);
		if (!flag)printf("Not Heap\n");
		else printf("Max Heap\n");
	}
	else {
		flag1 = false;
		dfs1(1);
		if (!flag)printf("Not Heap\n");
		else printf("Min Heap\n");
	}
	system("pause");
	return 0;
}