#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;
vector<int>in, pre;
struct node
{
	int data;
	node* l,*r;
};
void insert(node*&root,int x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->l = NULL;
		root->r = NULL;
		return;
	}
	if (abs(root->data) < abs(x)) {
		insert(root->r, x);
	}
	else
		insert(root->l, x);
}
set <int>st;
bool flag = false;
void dfs(node*root,int cnt) {
	if (flag)return;
	if (root == NULL) {
		st.insert(cnt);
		return;
	}
	if (root->data < 0) {
		if (root->l != NULL && root->l->data < 0)flag = true;
		if (root->r != NULL && root->r->data < 0)flag = true;
	}
	if (root->data > 0) 
		dfs(root->l, cnt + 1);
	else dfs(root->l, cnt);
	if (root->data > 0)
		dfs(root->r, cnt + 1);
	else dfs(root->r, cnt);
}
int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		flag = false;
		st.clear();
		int n;
		cin >> n;
		node *root = NULL;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			insert(root, t);
		}
		if (root->data < 0) {
			printf("No\n");
			continue;
		}
		dfs(root, 0);
		if (st.size() == 1 && !flag)printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}