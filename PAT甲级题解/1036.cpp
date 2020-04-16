#include<iostream>
#include<string>
using namespace std;
struct node {
	string name;
	char sex;
	string id;
	int grade;
}a[1000];
int main() {
	int m;
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++)
		cin >> a[i].name >> a[i].sex >> a[i].id >> a[i].grade;
	int index1 = -1, index2 = -1;
	int maxgrade = -1, mingrade = 101;
	for (int i = 0; i < m; i++) {
		if (a[i].sex == 'M'&&a[i].grade < mingrade) index1 = i, mingrade = a[i].grade;
		if (a[i].sex == 'F'&&a[i].grade > maxgrade) index2 = i, maxgrade = a[i].grade;
	}
	if (index2 == -1)printf("Absent\n");
	else cout << a[index2].name << " " << a[index2].id << endl;

	if (index1 == -1)printf("Absent\n");
	else cout << a[index1].name << " " << a[index1].id << endl;
	if (index1 == -1 || index2 == -1)printf("NA");
	else printf("%d", a[index2].grade - a[index1].grade);
	system("pause");
	return 0;
}