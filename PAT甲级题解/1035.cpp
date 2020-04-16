#include<iostream>
#include<string>
using namespace std;
string a[1000], b[1000];

bool replace1(bool flag, int i) {
	for (int j = 0; j < b[i].size(); j++) {
		if (b[i][j] == '1')b[i][j] = '@', flag = true;//°Ñ=Ð´³É==
		else if (b[i][j] == '0')b[i][j] = '%', flag = true;
		else if (b[i][j] == 'l')b[i][j] = 'L', flag = true;
		else if (b[i][j] == 'O')b[i][j] = 'o', flag = true;
	}
	return flag;
}

int main() {
	int m;
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++) 
		cin >> a[i] >> b[i];
	int rep[1000] = { 0 };
	for (int i = 0; i < m; i++) {
		bool flag = false;
		flag = replace1(flag, i);
		if (flag)rep[i] = 1;
	}
	int sum=0;
	int p;
	for (int i = 0; i < m; i++) {
		sum += rep[i];
		if (rep[i] != 0)p = i;
	}
	if (sum == 0) {
		if(m==1)
			printf("There is %d account and no account is modified", m);
		else 
			printf("There are %d accounts and no account is modified", m);
		system("pasue");
		return 0;
	}
	printf("%d\n", sum);
	for (int i = 0; i < p; i++) 
		if (rep[i] == 1) 
			cout << a[i] << " " << b[i] << endl;
	cout << a[p] << " " << b[p];
	system("pause");
	return 0;
}