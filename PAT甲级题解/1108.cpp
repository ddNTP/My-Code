#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;
vector<string>v1, v2;
int main() {
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int j = 0;
		if (s[0] == '-')j++;
		bool flag = false;
		for (; j < s.size(); j++) {
			if (isdigit(s[j])) continue;
			else if (s[j] == '.') {
				int num = 0;
				for (++j; j < s.size(); j++) {
					if (num == 2) {
						flag = true;
						break;
					}
					if (isdigit(s[j])) {
						num++;
						continue;
					}
					else {
						flag = true;
						break;
					}
					
				}
			}
			else {
				flag = true;
				break;
			}
			if (flag)break;
		}
		if (!flag) {
			double num = stod(s);
			if(num<=1000&&num>=-1000)
				v1.push_back(s);
			else v2.push_back(s);
		}
		else v2.push_back(s);
	}
	for (int i = 0; i < v2.size(); i++)
		cout << "ERROR: " << v2[i] << " is not a legal number" << endl;
	if (v1.size() == 0)
		cout << "The average of 0 numbers is Undefined";
	else if (v1.size() == 1)
		printf("The average of 1 number is %.2f", stod(v1[0]));
	else {
		double ave = 0;
		for (int i = 0; i < v1.size(); i++)
			ave = ave + stod(v1[i]) / v1.size();
		printf("The average of %d numbers is %.2f", v1.size(), ave);
	}
	system("pause");
	return 0;
}