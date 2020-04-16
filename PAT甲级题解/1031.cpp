#include<iostream>
#include<string>
using namespace std;
int main() {
	string a;
	cin >> a;
	int n1, n2, n3;
	int n = a.length();
	bool flag = true;
	int i = 3;
	while (flag) {
		for (int j = i; j > 0; j--) {
			if (2*j + i == n + 2) {
				n1 = n3 = j;
				n2 = i;
				flag = false;
				break;
			}
		}
		i++;
	}
	int size = a.length();
	string block;
	for (i = 0; i < n2 - 2; i++)
		block += " ";
	for (i = 0; i < n1 - 1; i++)
		cout << a[i] << block << a[size - 1 - i]<<endl;
	for (i = n1 - 1; i < n1 + n2 - 1; i++)
		cout << a[i];
	system("pause");
	return 0;
}