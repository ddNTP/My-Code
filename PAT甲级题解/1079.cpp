#include<iostream>
#include<vector>
using namespace std;
struct node
{
	double price;
	double sale;
	vector<int>child;
}tree[100010];
double t;
void dfs(int root, double price) {
	tree[root].price = price;
	for (int i=0; i < tree[root].child.size(); i++) {
		dfs(tree[root].child[i], price*(100 + t) / 100);
	}
}
double sum = 0;
void reckon(int root) {
	if (tree[root].child.size() == 0)sum += tree[root].price*tree[root].sale;
	for (int i = 0; i < tree[root].child.size(); i++) {
		reckon(tree[root].child[i]);
	}
}
int main() {
	int n;
	double p;
	cin >> n >> p >> t;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			tree[i].child.push_back(b);
		}
		if (a == 0) {
			double b;
			cin >> b;
			tree[i].sale = b;
		}
	}
	dfs(0, p);
	reckon(0);
	printf("%.1f", sum);
	system("pause");
	return 0;
}