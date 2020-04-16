#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int id;
	int grade[4];
	int rank[4];
	int best;
}stu[2001];
int check[2001];
int flag = -1;
int exist[1000000];
bool cmp1(node a, node b) { return (a.grade[flag] > b.grade[flag]); }//重点
int main() {
	char a[] = { 'A','C','M','E'};
	int n, m;
	scanf_s("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0+0.5;
		exist[stu[i].id] = i;
	}
	for (flag = 0; flag < 4; flag++) {
		sort(stu, stu + n, cmp1);//重点
		stu[0].rank[flag] = 1;
		stu[0].best = flag;
		for (int i = 1; i < n; i++) {
			if (stu[i].grade[flag] == stu[i - 1].grade[flag]) {
				stu[i].rank[flag] = stu[i - 1].rank[flag];
				continue;
			}
			else stu[i].rank[flag] = i+1;
		}
	}
	for (int i = 0; i < n; i++) {
		exist[stu[i].id] = i+1;           //重点
		int best = 0;
		int min = stu[i].rank[best];
		for (int j = 1; j < 4; j++) {
			if (min > stu[i].rank[j]) {
				best = j;
				min = stu[i].rank[j];
			}
		}
		stu[i].best = best;
	}
	int t;
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &t);
		int tmp = stu[exist[t]-1].best;
		int j = exist[t]-1;
		if (exist[t]) 
			cout << stu[j].rank[tmp] << " " << a[tmp];
		else 
			cout << "N/A";
		if (i != m - 1)cout << endl;
	}
	system("pause");
	return 0;
}