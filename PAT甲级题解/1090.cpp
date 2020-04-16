#include<iostream>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
struct node
{
	int layout;
}no[100010];
map<int, vector<int>>m;
void rec(int root) {
	if (root == -1) {
		no[m[root][0]].layout = 0;
		rec(m[root][0]);
	}
	else {
		for (int i = 0; i < m[root].size(); i++) {
			no[m[root][i]].layout = no[root].layout + 1;
			rec(m[root][i]);
		}
	}
}
int main() {
	int n;
	double p, t;
	cin >> n >> p >> t;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		m[t].push_back(i);
	}
	rec(-1);
	int max=0;
	for (int i = 0; i < n; i++) {
		if (max < no[i].layout)max = no[i].layout;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (no[i].layout == max)cnt++;
	}
	double price;
	price = p * pow((100 + t) / 100, max);
	printf("%.2f %d", price, cnt);
	system("pause");
	return 0;
}