#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int>v[2501];
int getid(char name[]) {
	int id = 0;
	for (int i = 0; i < 3; i++)
		id = id * 26 + name[i] - 'A';
	id = id * 10 + name[3] - '0';
	return id;
}
char tmp[6];
void getname(int n) {
	int t = n % 10;
	tmp[3] = t + '0';
	n = n / 10;
	for (int i = 2; i >= 0; i--) {
		t = n % 26;
		tmp[i] = t + 'A';
		n = n / 26;
	}
	tmp[4] = '\0';
}
int main() {
	int n, k;
	cin >> n >> k;
	char name[6];
	int c, t;
	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			scanf("%d", &t);
			int id = getid(name);
			v[t].push_back(id);
		}
	}
	for (int i = 1; i <= k; i++) {
		sort(v[i].begin(), v[i].end());
		printf("%d %d\n", i, v[i].size());
		for (int j = 0; j < v[i].size(); j++) {
			getname(v[i][j]);
			printf("%s\n", tmp);
		}
	}
	system("pause");
	return 0;
}