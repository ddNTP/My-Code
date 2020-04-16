#include<iostream>
#include<cmath>
#include<map>
using namespace std;
bool isprime(int n) {
	if (n <= 1)return false;
	int sqr = sqrt(n*1.0);
	for (int i = 2; i <= sqr; i++)
		if (n%i == 0)return false;
	return true;
}
int arr[10010];
bool arr1[10010];
int main() {
	int size, n;
	cin >> size >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = size;; i++) {
		if (isprime(i)) {
			size = i;
			break;
		}
	}
	map<int, int>m;
	for (int i = 0; i < n; i++) {
		int t = arr[i] % size;
		if (arr1[t] == true) {
			bool flag = true;
			for (int j = 1; j <= size; j++) {
				if (arr1[(t + j * j) % size] == false) {
					arr1[(t + j * j) % size] = true;
					m[arr[i]] = (t + j * j) % size;
					flag = false;
					break;
				}
			}
			if (flag) {
				m[arr[i]] = -1;
			}
		}
		else {
			arr1[t] = true;
			m[arr[i]] = t;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0)printf(" ");
		if (m[arr[i]] == -1)printf("-");
		else printf("%d", m[arr[i]]);
	}
	system("pause");
	return 0;
}