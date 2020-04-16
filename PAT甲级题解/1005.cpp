#include<iostream>
#include<string>
using namespace std;
int main() {
	int a;
	cin >> a;
	string b = to_string(a);
	int sum = 0;
	for (int i = 0; i < b.length(); i++)
		sum += (b[i]-'0');
	string c = to_string(sum);
	string d[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	cout << d[c[0] - '0'];
	for (int i = 1; i < c.length(); i++) //i=1Ð´³Éi=0
		cout <<" " << d[c[i] - '0'];
	return 0;
}