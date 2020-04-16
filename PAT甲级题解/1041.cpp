#include<iostream>
#include<unordered_map>
using namespace std;
int m[100010];
int main(){
	unordered_map<int, int>a;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
		if (a.count(m[i]) == 0)a[m[i]] = 1;
		else a[m[i]]++;
	}
	for (int i = 0; i < n; i++) 
		if (a[m[i]] == 1) { printf("%d", m[i]); return 0; }
	printf("None");
	return 0;
}