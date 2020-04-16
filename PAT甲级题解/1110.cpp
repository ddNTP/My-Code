#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct node
{
	int left, right;
	int index;
};
bool have[30];
node tree[30];
int ans[30];
int n;
void dfs(int root,int index) {
	if (root == -1 || index > n)return;
	ans[index] = tree[root].index;
	dfs(tree[root].left, index * 2);
	dfs(tree[root].right, index * 2 + 1);
}
int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (a != "-") {
			int t = stoi(a);
			tree[i].left = t;
			have[t] = true;
		}
		else tree[i].left = -1;
		if (b != "-") {
			int t = stoi(b);
			tree[i].right = t;
			have[t] = true;
		}
		else tree[i].right = -1;
		tree[i].index = i;
	}
	int root = 0;
	for (; root < n; root++)if (!have[root])break;
	for (int i = 0; i < 30; i++) {
		ans[i] = -1;
	}
	dfs(root,1);
	int i;
	for ( i = 1; i <= n; i++) {
		if (ans[i] == -1)break;
	}
	if (i != n + 1) {
		printf("NO %d", root);
	}
	else {
		printf("YES %d", ans[n]);
	}
	system("pause");
	return 0;
}