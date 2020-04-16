#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int data;
	node *lc, *rc;
};
vector<int>v[4];
void insert(node*&a, int b) {
	if (a == NULL) {
		a = new node;
		a->data = b;
		a->lc = NULL;
		a->rc = NULL;
		return;
	}
	if (a->data > b)insert(a->lc, b);
	else insert(a->rc, b);
}
void preorder(node *root) {
	if (root == NULL)return;
	v[1].push_back(root->data);
	preorder(root->lc);
	preorder(root->rc);
}
void postorder(node *root) {
	if (root == NULL)return;
	postorder(root->lc);
	postorder(root->rc);
	v[2].push_back(root->data);
}
void exchange(node *&root) {
	if (root == NULL)return;
	exchange(root->lc);
	exchange(root->rc);
	node *t = new node;
	t = root->lc;
	root->lc = root->rc;
	root->rc = t;
}
int main() {
	int n;
	cin >> n;
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		insert(root, t);
		v[0].push_back(t);
	}
	preorder(root);
	int i;
	for (i = 0; i < v[0].size(); i++) 
		if (v[0][i] != v[1][i])break;
	if (i != v[0].size()) {
		v[1].clear();
		exchange(root);
		preorder(root);
		for (i = 0; i < v[0].size(); i++)
			if (v[0][i] != v[1][i])break;
		if (i != v[0].size()) {
			printf("NO");
			system("pause");
			return 0;
		}
		postorder(root);
		printf("YES\n");
		for (int i = 0; i < v[2].size(); i++) {
			printf("%d", v[2][i]);
			if (i != v[2].size() - 1)printf(" ");
		}
		system("pause");
		return 0;
	}
	postorder(root);
	printf("YES\n");
	for (int i = 0; i < v[2].size(); i++) {
		printf("%d", v[2][i]);
		if (i != v[2].size() - 1)printf(" ");
	}
	system("pause");
	return 0;
}