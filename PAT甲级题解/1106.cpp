#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
struct node
{
	int lay;
	vector<int>child;
}tree[100010];
bool isleaf[100010];
void getlay(int root) {
	if (root == 0) {
		tree[root].lay = 0;
	}
	for (int i = 0; i < tree[root].child.size(); i++) {
		int t = tree[root].child[i];
		tree[t].lay = tree[root].lay + 1;
		getlay(t);
	}
	if (tree[root].child.size() == 0)isleaf[root] = true;
}
int main() {
	int n;
	double p, t;
	cin >> n >> p >> t;
	for (int i = 0; i < n; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int a;
			cin >> a;
			tree[i].child.push_back(a);
		}
	}
	getlay(0);
	int min = 9999999;
	for (int i = 0; i < n; i++) 
		if (isleaf[i]) 
			if (min > tree[i].lay)min = tree[i].lay;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (isleaf[i])
			if (min == tree[i].lay)cnt++;
	double price;
	price = p * pow((100 + t) / 100, min);
	printf("%.4f %d", price, cnt);
	system("pause");
	return 0;
}