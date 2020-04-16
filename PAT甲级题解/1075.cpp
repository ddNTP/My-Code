#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int id;
	int score[6];
	bool take_part=false;
	int total_score;
	int rank;
	int perfect;
}user[10010];
bool cmp1(node a, node b) {
	if (a.total_score != b.total_score)return a.total_score > b.total_score;
	else if (a.total_score == b.total_score&&a.perfect != b.perfect)return a.perfect > b.perfect;
	else return a.id < b.id;
}
void init() {
	for (int i = 0; i < 10010; i++) 
		for (int j = 0; j < 6; j++)
			user[i].score[j] = -2;
}
int main() {
	init();
	int n, k, m;
	scanf_s("%d%d%d",&n, &k, &m);
	int ques[6];
	for (int i = 1; i <= k; i++)
		scanf_s("%d", &ques[i]);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf_s("%d%d%d", &a, &b, &c);
		if (c >= 0)user[a].take_part = true;
		user[a].id = a;
		if (user[a].score[b] < c) {
			if (c == -1) {
				user[a].score[b] = c;
				continue;
			}
			if (user[a].score[b] <= 0)user[a].total_score += c;
			else user[a].total_score = user[a].total_score - user[a].score[b] + c;
			user[a].score[b] = c;
			if (c == ques[b])user[a].perfect++;
		}
	}
	sort(user + 1, user + 1 + n, cmp1);
	user[1].rank = 1;
	for (int i = 2; i <= n; i++) {
		if (user[i].total_score == user[i - 1].total_score)user[i].rank = user[i - 1].rank;
		else user[i].rank = i;
	}
	for (int i = 1; i <= n; i++) 
		if (user[i].take_part) {
			printf("%d %05d %d", user[i].rank, user[i].id,user[i].total_score);
			for (int j = 1; j <= k; j++) 
				if (user[i].score[j] >= 0)printf(" %d", user[i].score[j]);
				else if (user[i].score[j] == -1)printf(" 0");
				else printf(" -");
			printf("\n");
		}
	system("pause");
	return 0;
}