#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool ispn(string s) {
	string s1 = s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++) 
		if (s[i] != s1[i])return false;
	return true;
}
string add(string s) {
	string s1 = s;
	reverse(s.begin(), s.end());
	int carry = 0;
	string sum;
	for (int i = s.size()-1; i >=0; i--) {
		int num = s[i] - '0';
		int num1 = s1[i] - '0';
		num = num + num1 + carry;
		carry = num / 10;
		num = num % 10;
		sum.push_back(num + '0');
	}
	if (carry != 0)sum.push_back(carry + '0');
	reverse(sum.begin(), sum.end());
	return sum;
}
int main(){
	string s;
	cin >> s;
	int k;
	cin >> k;
	int i;
	for ( i = 0; i < k; i++) {
		if (ispn(s))break;
		s = add(s);
	}
	cout << s << endl << i;
	system("pause");
	return 0;
}