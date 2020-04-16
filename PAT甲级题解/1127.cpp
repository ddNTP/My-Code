#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int>in, post;
struct node
{
	int data;
	node *l, *r;
	int lay;
};
void create(node* &root, int inl, int inr, int postl, int postr,int lay) {
	if (inr < inl)return;
	if (inl == inr) {
		root = new node;
		root->l = NULL;
		root->r = NULL;	
		root->data = in[inl];
		root->lay = lay;
		return;
	}
	root = new node;
	root->l = NULL;
	root->r = NULL;
	root->data = post[postr];
	root->lay = lay;
	int i = inl;
	while (in[i] != post[postr])i++;
	create(root->l, inl, i - 1, postl, postl + i - inl - 1, lay + 1);
	create(root->r, i + 1, inr, postl + i - inl, postr - 1, lay + 1);
}
vector<int>lev[100];
void levelorder(node *root) {
	queue<node*>q;
	q.push(root);
	while (!q.empty()) {
		node* t = q.front();
		q.pop();
		lev[t->lay].push_back(t->data);
		if (t->l != NULL)q.push(t->l);
		if (t->r != NULL)q.push(t->r);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		in.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		post.push_back(t);
	}
	node *root;
	create(root, 0, n - 1, 0, n - 1, 0);
	levelorder(root);
	vector<int>ans;
	for (int i = 0; i < 100; i++) {
		if (lev[i].size() == 0)break;
		if (i % 2 == 0) {
			for (int j = lev[i].size() - 1; j >= 0; j--) {
				ans.push_back(lev[i][j]);
			}
		}
		else {
			for (int j = 0; j < lev[i].size(); j++) {
				ans.push_back(lev[i][j]);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
		if (i != ans.size() - 1)printf(" ");
	}
	system("pause");
	return 0;
}