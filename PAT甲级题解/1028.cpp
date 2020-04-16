#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node {
	int id;
	char name[10];
	int score;
}stu[100010];
bool cmp1(node a, node b) { return a.id < b.id; }
bool cmp2(node a, node b) { return strcmp(a.name, b.name) != 0 ? strcmp(a.name, b.name) < 0 : a.id < b.id; }
bool cmp3(node a, node b) { return a.score != b.score ? a.score < b.score : a.id < b.id; }
int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) 
		scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
	if (c == 1)sort(stu, stu + n, cmp1);
	else if (c == 2)sort(stu, stu + n, cmp2);
	else sort(stu, stu + n, cmp3);
	for (int i = 0; i < n; i++) {
		printf("%06d %s %d", stu[i].id, stu[i].name, stu[i].score);
		if (i != n - 1)printf("\n");
	}
	return 0;
}