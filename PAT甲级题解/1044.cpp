#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector <int>sum;
	int b;
	sum.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> b;
		sum.push_back(sum[i] + b);
	}
	vector <int>res;
	res.push_back(0);
	for (int i = 0; i <= n; i++) {
		int p = m + sum[i];
		int j = lower_bound(sum.begin() + i, sum.end(), p) - sum.begin();
		if(j!=n+1)res.push_back(j);
		else break;
	}
	vector<int>q;
	q.push_back(0);
	for (int i = 1; i < res.size(); i++) {
		int t = res[i];
		q.push_back(sum[t] - sum[i-1]);
	}
	int min =100000000;//注意min的取值至少大于M
	for (int i = 1; i < q.size(); i++) 
		if (q[i] < min)min = q[i];
	for (int i = 1; i < res.size(); i++)
		if (q[i] == min)printf("%d-%d\n", i, res[i]);
	system("pause");
	return 0;
}