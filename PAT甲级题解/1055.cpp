#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	char name[10];
	int age;
	int net;
};

bool cmp1(node a,node b) {
	if (a.net != b.net)return a.net > b.net;
	else if (a.net == b.net&&a.age != b.age)return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}
int main() {
	int n, k;
	int book[210] = {0};
	scanf_s("%d%d", &n, &k);
	vector <node> vt(n), v;
	for (int i = 0; i < n; i++) 
		cin >> vt[i].name >> vt[i].age >> vt[i].net;
	int a, b, c;
	sort(vt.begin(), vt.end(), cmp1);
	for (int i = 0; i < n; i++) 
		if (book[vt[i].age] < 100) {
			v.push_back(vt[i]);
			book[vt[i].age]++;
		}
	
	for (int i = 0; i < k; i++) {
		scanf_s("%d%d%d", &a, &b, &c);
		if(i==0)printf("Case #1:\n");
		if (i != 0)printf("Case #%d:\n", i + 1);
		int m = a;
		for (int j = 0; j < v.size() && a>0; j++)
			if (v[j].age >= b && v[j].age <= c) {
				printf("%s %d %d\n", v[j].name, v[j].age, v[j].net);
				a--;
			}
		if (a ==m)printf("None\n");
	}
	system("pause");
	return 0;
}