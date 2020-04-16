#include<iostream>
#include<string>
using namespace std;
int main() {
	string num[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	string w[] = { "Shi","Bai","Qian","Wan","Yi" };
	string a;
	cin >> a;
	int length=a.length();
	if (a[0] == '-') {
		printf("Fu ");
		length--;
		a = a.substr(1, length);
	}
	if (length == 1) {
		cout << num[a[0]-'0']; system("pause"); return 0;
	}
	cout << num[a[0] - '0'] << " ";
	if (length == 9)
		cout << w[4];
	else
		cout << w[(length - 2) % 4];
	int j = 1;
	for (int i = length-1; i > 1; i--,j++) {
		if (a[j] == '0') {
			if (a[j - 1] == '0') continue;
			else {
				if (i<5&&stoi(a.substr(length - i, i)) == 0) { system("pause"); return 0; }
				else if (i >= 5 && (stoi(a.substr(length - i, i - 4))) == 0) { cout << " " << w[3]; if ((stoi(a.substr(length - i, i))) != 0)cout << " " << num[0]; }
				else cout << " " << num[0];
			}
		}
		else {
			cout << " " << num[a[j] - '0'];
			if (i == 9)
				cout << " " << w[4];
			else
				cout << " " << w[(i - 2) % 4];
		}
	}
	if(a[length-1]!='0')
		cout <<" "<< num[a[length-1]-'0'];
	system("pause");
	return 0;
}