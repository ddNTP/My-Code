#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp1(int a, int b) { return a > b; }
int main() {
	vector<int>a, b, c, d;
	int n1, n2;
	cin >> n1;
	int m;
	for (int i = 0; i < n1; i++) {
		cin >> m;
		if (m > 0)a.push_back(m);
		else if (m < 0)b.push_back(m);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> m;
		if (m > 0)c.push_back(m);
		else if (m < 0)d.push_back(m);
	}
	sort(a.begin(), a.end(), cmp1);
	sort(c.begin(), c.end(), cmp1);
	sort(b.begin(), b.end());
	sort(d.begin(), d.end());
	int max1 = min(a.size(), c.size());
	int max2 = min(b.size(), d.size());
	int sum=0;
	for (int i = 0; i < max1; i++) 
		sum += a[i] * c[i];
	for (int i = 0; i < max2; i++)
		sum += b[i] * d[i];
	printf("%d", sum);
	system("pause");
	return 0;
}