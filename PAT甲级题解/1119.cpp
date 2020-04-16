#include<iostream>
#include<vector>
using namespace std;
vector <int>pre, post;
bool unique = true;
vector<int>ans;
void in(int prel, int prer, int postl, int postr) {
	if (prel == prer) {
		ans.push_back(pre[prel]);
		return;
	}
	int i = prel + 1;
	while (i <= prer && pre[i] != post[postr - 1])i++;
	if (i - prel > 1)
		in(prel + 1, i - 1, postl, postl + i - prel - 2);
	else unique = false;
	ans.push_back(post[postr]);
	in(i, prer, postl + i - prel - 1, postr - 1);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		pre.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		post.push_back(t);
	}
	in(0, n - 1, 0, n - 1);
	if (unique)printf("Yes\n");
	else printf("No\n");
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
		if (i != ans.size() - 1)printf(" ");
	}
	printf("\n");
	system("pause");
	return 0;
}