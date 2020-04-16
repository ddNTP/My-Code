#include<iostream>
#include<string>
#include<queue>
using namespace std;
string s[10];
bool have[10];
int lev[100];
int in[100];
struct node
{
	int data;
	node *lc, *rc;
};
node *create(int root) {
	node *r = new node;
	r->data = root;
	if (s[root][0] != '-')
		r->rc = create(s[root][0] - '0');
	else r ->rc = NULL;
	if (s[root][2] != '-')
		r ->lc = create(s[root][2] - '0');
	else r->lc = NULL;
	return r;
}
int cnt = 0;
void levelorder(node *root) {
	queue<node*>q;
	q.push(root);
	while (!q.empty()) {
		node*t = q.front();
		q.pop();
		lev[cnt++] = t->data;
		if (t->lc != NULL)q.push(t->lc);
		if (t->rc != NULL)q.push(t->rc);
	}
}
int cnt1 = 0;
void inorder(node*root) {
	if (root == NULL)return;
	inorder(root->lc);
	in[cnt1++] = root->data;
	inorder(root->rc);
}
int main() {
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
		if (s[i][0] != '-') 
			have[s[i][0] - '0'] = true;
		if (s[i][2] != '-')
			have[s[i][2] - '0'] = true;
	}
	int root;
	for (root = 0; root < n; root++)
		if (!have[root])break;
	node *r = create(root);
	levelorder(r);
	inorder(r);
	printf("%d", lev[0]);
	for (int i = 1; i < cnt; i++) 
		printf(" %d", lev[i]);
	cout << endl;
	printf("%d", in[0]);
	for (int i = 1; i < cnt1; i++)
		printf(" %d", in[i]);
	system("pause");
	return 0;
}