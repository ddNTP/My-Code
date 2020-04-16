#include<iostream>
#include<algorithm>
using namespace std;
int num1[110], num2[110];
void downadjust(int low,int high) {
	int i = low, j = 2 * i;
	while (j <= high) {
		if (j + 1 <= high&&num1[j+1]>num1[j]) {
			j = j + 1;
		}
		if (num1[j] > num1[i]) {
			swap(num1[j], num1[i]);
			i = j;
			j = 2 * i;
		}
		else break;
	}
}
int main() {
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> num1[i];
	for (int i = 1; i <= n; i++)
		cin >> num2[i];
	int m = 0;
	while (num2[m] <= num2[m + 1])m++;
	m++;
	int a = m;
	for (; a <= n; a++)
		if (num1[a] != num2[a])break;
	if (a == n + 1) {
		printf("Insertion Sort\n");
		sort(num2 + 1, num2 + m + 1);
		for (int i = 1; i <= n; i++) {
			printf("%d", num2[i]);
			if (i != n)printf(" ");
		}
		system("pause");
		return 0;
	}
	printf("Heap Sort\n");
	m = n;
	for (int i = n / 2; i >= 1; i--) 
		downadjust(i, n);
	for (int i = 0; i < n; i++) {
		swap(num1[n--], num1[1]);
		downadjust(1, n);
		int j;
		for (j = 1; j <= n; j++)
			if (num1[j] != num2[j])break;
		if (j == n + 1) 
			break;
	}
	swap(num1[n--], num1[1]);
	downadjust(1, n);
	for (int i = 1; i <= m; i++) {
		printf("%d", num1[i]);
		if (i != m)printf(" ");
	}
	system("pause");
	return 0;
}