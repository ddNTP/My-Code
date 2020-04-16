#include<iostream>
#include<queue>
using namespace std;
int pos[40], in[40];
struct node
{
	node*lc, *rc;
	int data;
};
node*create(int posl, int posr, int inl, int inr) {
	if (posl > posr)return NULL;
	node*root = new node;
	root->data = pos[posr];
	int k;
	for (k = inl; k <= inr; k++) 
		if (in[k] == pos[posr])break;
	int numl = k - inl;
	root->lc = create(posl, posl + numl - 1, inl, k - 1);
	root->rc = create(posl + numl, posr - 1, k + 1, inr);
	return root;
}
void levelorder(node *root) {
	queue<node*>q;
	q.push(root);
	bool flag = true;
	while (!q.empty()) {
		node *t = q.front();
		q.pop();
		if (flag) {
			printf("%d", t->data);
			flag = false;
		}
		else
		{
			printf(" %d", t->data);
		}
		if (t->lc != NULL)q.push(t->lc);
		if (t->rc != NULL)q.push(t->rc);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pos[i];
	for (int i = 0; i < n; i++) 
		cin >> in[i];
	node *root = create(0, n - 1, 0, n - 1);
	levelorder(root);
	system("pause");
	return 0;
}