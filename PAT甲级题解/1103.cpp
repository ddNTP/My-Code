#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int k, maxsum = -1, n, p,sqr;
vector<int >tmp, ans;
void dfs(int index, int nowk, int sum,int sumsqu) {
	if (nowk == k && sumsqu == n) {
		if (sum > maxsum) {
			maxsum = sum;
			ans = tmp;
		}
		return;
	}
	if (index == 0 || sumsqu > n || nowk > k)return;
	tmp.push_back(index);
	dfs(index, nowk + 1, sum + index, sumsqu + pow(index, p));
	tmp.pop_back();
	dfs(index - 1, nowk, sum, sumsqu);
}

int main() {
	cin >> n >> k >> p;
	sqr = sqrt(n);
	dfs(sqr, 0, 0, 0);
	if (ans.size() == 0) {
		printf("Impossible");
		system("pause");
		return 0;
	}
	printf("%d = %d^%d", n, ans[0], p);
	for (int i = 1; i < ans.size(); i++) {
		printf(" + %d^%d", ans[i], p);
	}
	system("pause");
	return 0;
}