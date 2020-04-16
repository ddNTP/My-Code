
#include<iostream>
#include<string>
using namespace std;
int main() {
	string a[55];
	for (int i = 1; i <= 13; i++) 
		a[i] = "S" + to_string(i);
	for (int i = 1; i <= 13; i++)
		a[i + 13] = "H" + to_string(i);
	for (int i = 1; i <= 13; i++)
		a[i + 26] = "C" + to_string(i);
	for (int i = 1; i <= 13; i++)
		a[i + 39] = "D" + to_string(i);
	a[53] = "J1";
	a[54] = "J2";
	int n;
	scanf("%d", &n);
	int c[54];
	for (int i = 0; i < 54; i++) 
		scanf("%d", &c[i]);
	string b[55];
	bool flag=true;
	for (int i = 0; i < n; i++) {
		if (flag) {
			for (int j = 0; j < 54; j++)
				b[c[j]] = a[j+1];
			flag = false;
		}
		else {
			for (int j = 0; j < 54; j++)
				a[c[j]] = b[j+1];
			flag = true;
		}
	}
	if (flag) {
		cout << a[1];
		for (int i = 2; i <= 54; i++)
			cout << " " << a[i];
	}
	else {
		cout << b[1];
		for (int i = 2; i <= 54; i++)
			cout << " " << b[i];
	}
	return 0;
}