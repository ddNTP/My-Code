#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[100], b[100];
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int i, j;
	for (i = 0; i<n-1&&b[i] <= b[i+1]; i++);
	for (j = i + 1; j < n&&a[j] == b[j]; j++);
	if (j == n) {
		cout << "Insertion Sort" << endl;
		sort(a, a + i + 2);
	}
	else {
		cout<< "Merge Sort" << endl;
		int k = 1, flag = 1;
		while (flag) {
			flag = 0;
			for (i = 0; i < n; i++) 
				if (a[i] != b[i]) {
					flag = 1;
					break;
				}
			k = k * 2;
			for (i = 0; i < n / k; i++) {
				sort(a + i * k, a + (i + 1)*k);
			}
			sort(a + n / k * k, a + n);
		}
	}
	for (i = 0; i < n; i++) {
		if (i != 0)printf(" ");
		printf("%d", a[i]);
	}
}