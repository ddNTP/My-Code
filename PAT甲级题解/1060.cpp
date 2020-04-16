#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n;
	string a,b;
	cin >> n >> a >> b;
	int m1 = 0, m2 = 0;
	bool flag1=true, flag2=true;
	for (int j = 0; j < a.size(); j++) {//去除前面的0
		if (a[j] =='0')continue;
		if (a[j] != '.')flag1 = true;
		else flag1 = false;
		if (flag1)a = a.substr(j, a.size() - j);
		else a = a.substr(j + 1, a.size() - j - 1);
		break;
	}
	for (int j = 0; j < b.size(); j++) {
		if (b[j] == '0')continue;
		if (b[j] != '.')flag2 = true;
		else flag2 = false;
		if (flag2)b = b.substr(j, b.size() - j);
		else b = b.substr(j + 1, b.size() - j - 1);
		break;
	}
	if(flag1) //去除后面的0
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == '.') { 
				a = a.substr(0, j) + a.substr(j + 1, a.size() - j - 1);
				break; 
			}
		m1++;
		}
	else {
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == '0')m1--;
			else {
				a = a.substr(j, a.size() - j);
				break;
			}
		}
	}
	if (flag2) 
		for (int j = 0; j < b.size(); j++) {
		if (b[j] == '.') {
			b = b.substr(0, j) + b.substr(j + 1, b.size() - j - 1);
			break;
		}
		m2++;
		}
	else {
		for (int j = 0; j < b.size(); j++) {
			if (b[j] == '0')m2--;
			else {
				b = b.substr(j, b.size() - j);
				break;
			}
		}
	}
	int i;
	if(n>a.size())a.insert(a.size(), n - a.size(), '0');
	if(n>b.size())b.insert(b.size(), n - b.size(), '0');
	a = a.substr(0, n);
	b = b.substr(0, n);
	bool flag = true;
	for (int j = 0; j < n; j++) {
		if (a[j] == '0'&&b[j] == '0')continue;
		else {
			flag = false;
			break;
		}
	}
	if (flag) {
		m1 = m2 = 0;
	}
	for ( i = 0; i < n; i++) {
		if (a[i] != b[i])break;
	}
	
	if (i==n&&m1==m2) {
		printf("YES ");
		printf("0.");
		cout << a << "*10^" << m1;
	}
	else {
		printf("NO ");
		printf("0.");
		cout << a << "*10^" << m1<<" ";
		printf("0.");
		cout << b << "*10^" << m2;
	}
	system("pause");
	return 0;
}