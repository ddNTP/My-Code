#include<iostream>
#include<string>
using namespace std;
struct node
{
	int data;
	node*lc, *rc;
};
int n;
string s[70];
int cnt = 0;
node*create() {
	if (cnt >= 2 * n)return NULL;
	if (s[cnt][1] == 'o')return NULL;
	node*root = new node;
	root->data = stoi(s[cnt].substr(5, s[cnt].size() - 5));
	cnt++;
	root->lc = create();
	cnt++;
	root->rc = create();
	return root;
}
int cnt1 = 0;
int pos[50];
void post(node *root) {
	if (root == NULL)return;
	post(root->lc);
	post(root->rc);
	pos[cnt1++] = root->data;
}
int main() {
	cin >> n;
	getchar();
	for (int i = 0; i < 2*n; i++)
		getline(cin, s[i]);
	node*root;
	root = create();
	post(root);
	printf("%d", pos[0]);
	for (int i = 1; i < cnt1; i++) 
		printf(" %d", pos[i]);
	system("pause");
	return 0;
}