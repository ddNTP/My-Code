#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	double profit;
	double tons;
	double ave;
}pro[1010];
bool cmp1(node a, node b) {
	return a.ave > b.ave;
}
int main() {
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		cin >> pro[i].tons;
	for (int i = 0; i < n; i++) {
		cin >> pro[i].profit;
		pro[i].ave = pro[i].profit / pro[i].tons;
	}
	sort(pro, pro + n, cmp1);
	double profit = 0;
	for (int i = 0; d > 0&&i<n; i++) {
		if (d >= pro[i].tons) {
			profit += pro[i].profit;
			d -= pro[i].tons;
		}
		else {
			profit = profit + d * pro[i].ave;
			break;
		}
	}
	printf("%.2f", profit);
	system("pause");
	return 0;
}