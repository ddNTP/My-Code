#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	if (s[0] == '-')printf("-");
	s = s.substr(1, s.length() - 1);
	int i = 0;
	for (; i < s.length(); i++) {
		if (s[i] == 'E')break;
	}
	string s1 = s.substr(0, i);
	string s2 = s.substr(i + 1, s.length() - i - 1);
	int exp = stoi(s2);
	if (exp == 0) {
		cout << s1;
		system("pause");
		return 0;
	}
	else if (exp > 0) {
		if (exp < s1.size() - 2) {
			cout << s1[0];
			for (int j = 0; j < exp; j++) {
				cout << s1[j + 2];
			}
			cout << ".";
			for (int j = exp + 2; j < s1.size(); j++) {
				cout << s1[j];
			}
		}
		else {
			cout << s1[0];
			for (int j = 2; j < s1.size(); j++)
				cout << s1[j];
			for (int j = 0; j < exp - s1.size() + 2; j++)
				cout << "0";
		}
	}
	else {
		printf("0.");
		string s3 = s1[0] + s1.substr(2, s1.size() - 2);
		for (int j = -1; j > exp; j--)
			cout << "0";
		cout << s3;
		
	}
	system("pause");
	return 0;
}