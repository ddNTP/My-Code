#include<iostream>
using namespace std;
struct  node
{
	int data;
	node *l, *r;
	int layer;
};
int maxlay;
int n1, n2;
void insert(node *&root,int data,int layer) {
	if (root == NULL) {
		root = new node;
		root->data = data;
		root->l = NULL;
		root->r = NULL;
		root->layer = layer;
		if (maxlay < layer)maxlay = layer;
		return;
	}
	if (root->data >= data)
		insert(root->l, data, layer + 1);
	else insert(root->r, data, layer + 1);
}
void dfs(node *root) {
	if (root == NULL) {
		return;
	}
	if (root->layer == maxlay)n1++;
	if (root->layer == maxlay - 1)n2++;
	dfs(root->l);
	dfs(root->r);
}
int main() {
	int n;
	cin >> n;
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		insert(root, t, 1);
	}
	dfs(root);
	printf("%d + %d = %d", n1, n2, n1 + n2);
	system("pause");
	return 0;
}