#include<iostream>
#include<vector>
using namespace std;
vector<int>ans;
int tree[1010];
int m, n;
bool flag;
int result;
void post1(int index) {
	if (index > n)return;
	post1(index * 2);
	post1(index * 2 + 1);
	if (index * 2 <= n && tree[index * 2] > tree[index])flag = false;
	if (index * 2 + 1 <= n && tree[index * 2 + 1] > tree[index])flag = false;
	ans.push_back(tree[index]);
}
void post2(int index) {
	if (index > n)return;
	post2(index * 2);
	post2(index * 2 + 1);
	if (index * 2 <= n && tree[index * 2] < tree[index])flag = false;
	if (index * 2 + 1 <= n && tree[index * 2 + 1] < tree[index])flag = false;
	ans.push_back(tree[index]);
}
int main() {

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) 
			cin >> tree[j];
		ans.clear();
		flag = true;
		if (tree[1] > tree[n]) {
			post1(1);
			if (flag)printf("Max Heap\n");
			else printf("Not Heap\n");
			for (int k = 0; k < ans.size(); k++) {
				printf("%d", ans[k]);
				if (k != ans.size() - 1)printf(" ");
			}
			printf("\n");
		}
		else if (tree[1] < tree[n]) {
			post2(1);
			if (flag)printf("Min Heap\n");
			else printf("Not Heap\n");
			for (int k = 0; k < ans.size(); k++) {
				printf("%d", ans[k]);
				if (k != ans.size() - 1)printf(" ");
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}