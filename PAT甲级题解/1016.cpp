#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	long long id;
	int score;
	int locatenum;
	int locaterank;
	int finalrank;
}stu[30010];
bool cmp1(node a, node b) { return a.score != b.score ? a.score > b.score:a.id < b.id; }
int main() {
	int n;
	int k;
	scanf_s("%d", &n);
	int now = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%d\n", &k);
		for (int j = 0; j < k; j++) {
			scanf_s("%lld%d", &stu[now+j].id, &stu[now+j].score);
			stu[now + j].locatenum = i + 1;
		}
		sort(stu + now, stu + now + k, cmp1);
		stu[now].locaterank = 1;
		for (int j = now + 1; j < now + k; j++) {
			if (stu[j].score == stu[j - 1].score)stu[j].locaterank = stu[j-1].locaterank;
			else stu[j].locaterank = j - now + 1;
		}
		now += k;
	}
	sort(stu, stu + now, cmp1);
	stu[0].finalrank = 1;
	for (int i = 1; i < now; i++) {
		if (stu[i].score == stu[i - 1].score)stu[i].finalrank = stu[i - 1].finalrank;
		else stu[i].finalrank = i + 1;
	}
	printf("%d\n", now);
	for (int i = 0; i < now-1; i++) 
		printf("%013lld %d %d %d\n", stu[i].id, stu[i].finalrank, stu[i].locatenum, stu[i].locaterank);//%013lld
	printf("%013lld %d %d %d", stu[now-1].id, stu[now-1].finalrank, stu[now-1].locatenum, stu[now-1].locaterank);//%013lld，不然过不去最后一个测试点
	system("pause");
	return 0;
}