#include<iostream>
using namespace std;
void main(int argc,char *argv[]) {
	char ss[80];
	char a;
	cout << "first string:";
	cin.get(ss, 80);
	cout << "first string:" << ss<<endl;
	cout << "second string:";
	cin.get(ss, 80);
	cout << "second string:" << ss << endl;
	cout << "third string:";
	cin.get(ss, 80);
	cout << "third string:" << ss << endl;
	system("pause");
}