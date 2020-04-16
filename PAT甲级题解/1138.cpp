#include<iostream>
#include<vector>
using namespace std;
vector<int>pre, in;
bool flag;
void dfs(int prel, int prer, int inl,int inr) {
	if (flag)return;
	if (prel > prer)return;
	if (prel == prer) {
		printf("%d", pre[prel]);
		flag = true;
		return;
	}
	int i = inl;
	while (in[i] != pre[prel])i++;
	dfs(prel + 1, prel + i - inl, inl, i - 1);
	dfs(prel + i - inl + 1, prer, i + 1, inr);
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
		in.push_back(t);
	}
	dfs(0, n - 1, 0, n - 1);
	system("pause");
	return 0;
}