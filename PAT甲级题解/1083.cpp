#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	char name[20];
	char id[20];
	int grade;
}a;
bool cmp1(node a, node b) { return a.grade > b.grade; }
int main() {
	int n;
	scanf_s("%d", &n);
	vector <node>v;
	for (int i = 0; i < n; i++) {
		cin >> a.name >> a.id >> a.grade;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp1);
	int min, max;
	scanf_s("%d%d", &min, &max);
	int count = 0;
	for (int i = 0; i < n; i++) 
		if (v[i].grade >= min && v[i].grade <= max) {
			cout << v[i].name << " " << v[i].id << endl;
			count++;
		}
	if (count == 0)printf("NONE");
	system("pause");
	return 0;
}