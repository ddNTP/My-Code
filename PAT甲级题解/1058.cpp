#include<iostream>
int main() {
	int a, b, c;
	int a1, b1, c1;
	scanf_s("%d.%d.%d %d.%d.%d", &a, &b, &c, &a1, &b1, &c1);
	int a2, b2, c2;
	a2 = a + a1;
	b2 = b + b1;
	c2 = c + c1;
	if (c2 >= 29)c2 -= 29, b2++;
	if (b2 >= 17)b2 -= 17, a2++;
	printf("%d.%d.%d", a2, b2, c2);
	system("pasue");
	return 0;
}