#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getid(char name[]) {
	int id = 0;
	for (int i = 0; i < 4; i++) {
		if (i <= 2) 
			id = id * 26 + name[i] - 'A';
		else id = id * 10 + name[i] - '0';
	}
	return id;
}
vector<int>a[26 * 26 * 26 * 10];
int main() {
	int n, k;
	cin >> n >> k;
	char name[10];
	for (int i = 0; i < k; i++) {
		int n1, n2;
		scanf_s("%d %d", &n1, &n2);
		for (int j = 0; j < n2; j++) {
			scanf_s("%s", name,6);
			int id = getid(name);
			a[id].push_back(n1);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf_s("%s", name,6);
		printf("%s", name);
		int id = getid(name);
		printf(" %d", a[id].size());
		sort(a[id].begin(), a[id].end());
		for (int j = 0; j < a[id].size(); j++) 
			printf(" %d", a[id][j]);
		if (i != k - 1)printf("\n");
	}
	system("pause");
	return 0;
}