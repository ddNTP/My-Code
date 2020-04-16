#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	reverse(s.begin(),s.end());
	vector<int>carr;
	int book[11] = { 0 };
	for (int i=0; i < s.size(); i++) {
		book[s[i] - '0']++;
	}
	for (int i = 0; i < s.size(); i++) {
		int carry = 0;
		int num = s[i] - '0';
		num *= 2;
		if (i != 0)num += carr[i - 1];
		carry = num / 10;
		num = num % 10;
		book[num]--;
		carr.push_back(carry);
		s[i] = '0' + num;
	}
	reverse(s.begin(), s.end());
	if (carr[s.size() - 1] > 0) {
		cout << "No" << endl;
		cout << carr[s.size() - 1] << s;
		system("pause");
		return 0;
	}
	for (int i = 0; i < 11; i++) {
		if (book[i] != 0) {
			cout << "No" << endl;
			cout << s;
			system("pause");
			return 0;
		}
	}
	cout << "Yes" << endl;
	cout << s;
	system("pause");
	return 0;
}