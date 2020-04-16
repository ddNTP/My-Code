#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100];
int maxdepth = -1;
int book[100];
void dfs(int index,int depth) {
	if (v[index].size() == 0) {
		book[depth]++;
		maxdepth = max(maxdepth, depth);
		return;
	}
	for (int i = 0; i < v[index].size(); i++) {//indexÐ´³ÉÁËdepth
		dfs(v[index][i], depth+1);
	}
}
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int a, b, c;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		for (int j = 0; j < b; j++) {
			scanf("%d", &c);
			v[a].push_back(c);
		}
	}
	dfs(1, 0);
	printf("%d", book[0]);
	for (int i = 1; i <= maxdepth; i++) 
		printf(" %d", book[i]);
	return 0;
}