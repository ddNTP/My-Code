#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sch[110] ;
int sch1[110];
struct node
{
	int num;
	int ge, gi;
	int sum;
	int wish[10];
	int rank;
}appl[40010];
bool cmp1(node a, node b) {
	if (a.sum != b.sum)return a.sum > b.sum;
	else return a.ge > b.ge;
}
bool cmp2(int a, int b) { return a < b; }
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> sch[i];
		sch1[i] = sch[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> appl[i].ge >> appl[i].gi;
		appl[i].sum = appl[i].ge + appl[i].gi;
		appl[i].num = i;
		for (int j = 0; j < k; j++)
			cin >> appl[i].wish[j];
	}
	sort(appl, appl + n, cmp1);
	appl[0].rank = 1;
	for (int i = 1; i < n; i++) 
		if (appl[i].sum == appl[i - 1].sum&&appl[i].ge == appl[i - 1].ge)appl[i].rank = appl[i - 1].rank;
		else appl[i].rank = i + 1;
	vector<int>v[100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int t = appl[i].wish[j];
			if (sch[t] > 0) {
				v[t].push_back(appl[i].num);//把i push进去了
				sch[t]--;
				break;
			}
			else 
				if (sch1[t]!=0&&appl[i].rank == appl[v[t][sch1[t] - 1]].rank) { v[t].push_back(appl[i].num); sch1[t]++; break; }//break写在else里面而不是if里面
		}//还要考虑sch1[t]为零越界的情况
	}
	for (int i = 0; i < m; i++) {
		if (v[i].size() != 0)sort(v[i].begin(), v[i].end(), cmp2);
		if (v[i].size() == 0)printf("\n");
		else {
			printf("%d", v[i][0]);
			for (int j = 1; j < v[i].size(); j++)
				printf(" %d", v[i][j]);
			printf("\n");
		}
	}
	system("pause");
	return 0;
}