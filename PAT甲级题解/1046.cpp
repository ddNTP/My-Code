#include<iostream>
#include<algorithm>
using namespace std;
int d[1000001];
int dis[100001];
int main() {
	int n,sum=0;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &d[i]);
		sum += d[i];
		dis[i] = sum;//要考虑时间复杂度问题，要对数据进行预处理
	}
	int m;
	scanf_s("%d", &m);
	int a, b;
	for (int i = 1; i <= m; i++) {
		scanf_s("%d%d", &a, &b);
		if (a > b)swap(a, b);
		int dis1, mindis;
		dis1 = dis[b] - dis[a] + d[a] - d[b];
		mindis = min(dis1, sum - dis1);
		if (i < m)
			printf("%d\n", mindis);
		else
			printf("%d", mindis);
	}

	system("pause");
	return 0;
}