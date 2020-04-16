#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	double dis;
	double price;
	double gas;
}sta[1000];

bool cmp1(node a, node b) {
	return a.dis < b.dis;
}
int main() {
	double cap, dis, ave;
	int num;
	cin >> cap >> dis >> ave >> num;
	for (int i = 0; i < num; i++)
		cin >> sta[i].price >> sta[i].dis;
	sta[num].dis = dis;
	sta[num].price = 0;
	sort(sta, sta + num+1, cmp1);
	if (sta[0].dis != 0) { printf("The maximum travel distance = 0.00"); system("pause"); return 0; }
	int cnt = 0;
	double price=0;
	double min=21;
	int min1=0;
	for (int i = 1; i < num + 1; i++) {
		if (sta[i].dis <= sta[cnt].dis + cap*ave && sta[i].price < sta[cnt].price) {
			double gas = (sta[i].dis - sta[cnt].dis) / ave;
			price += (gas - sta[cnt].gas)*sta[cnt].price;
			cnt = i;
			min1 = i+1;
			min = sta[i+1].price;
			if (sta[cnt].dis == dis) {
				printf("%.2f", price);
				system("pause");
				return 0;
			}
			continue;
		}
		
		if (sta[i].dis > sta[cnt].dis + cap*ave) {
			if (sta[min1].dis> sta[cnt].dis+cap*ave) {
				printf("The maximum travel distance = %.2f", sta[cnt].dis + cap*ave);
				system("pause");
				return 0;
			}
			double gas;
			gas = (sta[min1].dis - sta[cnt].dis) / ave;
			price +=(cap-sta[cnt].gas)* sta[cnt].price;
			sta[min1].gas = cap - gas;
			cnt = min1;
			i = min1;
			min = sta[i+1].price;
			min1 = i+1;
			continue;
		}
		if (min > sta[i].price) {
			min = sta[i].price;
			min1 = i;
		}
	}
	system("pause");
	return 0;
}