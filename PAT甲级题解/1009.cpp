#include<iostream>
#include<vector>
using namespace std;
vector <int> a;
vector <float>b;
int main() {
	float p[1001] = {0};
	int k1,t;
	float t1;
	scanf_s("%d", &k1);
	for (int i = 0; i < k1; i++) {
		scanf_s("%d%f", &t, &t1);
		a.push_back(t);
		b.push_back(t1);
	}
	int k2;
	scanf_s("%d", &k2);
	for (int i = 0; i < k2; i++) {
		scanf_s("%d%f", &t, &t1);
		for (int j = 0; j < a.size(); j++) 
			p[a[j] + t] += b[j] * t1;
	}
	int count=0;
	for (int i = 0; i < 2001; i++)
		if (p[i] != 0)count++;
	printf("%d", count);
	for (int i = 2001; i >= 0; i--)
		if (p[i] != 0)
			printf(" %d %.1f", i, p[i]);
	system("pause");
	return 0;
}