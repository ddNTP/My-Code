#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>v[1000];
vector<int>ve;
int n;
struct node
{
	int data;
	node *rc, *lc;
};
node* create(node*&root,int index) {
	root = new node;
	if (v[index][0] == -1)root->lc = NULL;
	else root->lc = create(root->lc, v[index][0]);
	if (v[index][1] == -1)root->rc = NULL;
	else root->rc = create(root->rc, v[index][1]);
	return root;
}
int cnt = 0;
void fill(node *&root) {
	if (root == NULL)return;
	fill(root->lc);
	root->data = ve[cnt++];
	fill(root->rc);
}
int cnt1 = 0;
void levelorder(node *root) {
	queue<node*>q;
	q.push(root);
	while (!q.empty()) {
		node *t = q.front();
		q.pop();
		cnt1++;
		printf("%d", t->data);
		if (cnt1 != n)printf(" ");
		if (t->lc != NULL)q.push(t->lc);
		if (t->rc != NULL)q.push(t->rc);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v[i].push_back(t1);
		v[i].push_back(t2);
	}
	node *root;
	root = create(root, 0);

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		ve.push_back(t);
	}
	sort(ve.begin(), ve.end());
	fill(root);
	levelorder(root);
	system("pause");
	return 0;
}