#include<iostream>
int main() {
	int a[3];
	char d[13] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };
	scanf_s("%d%d%d", &a[0], &a[1], &a[2]);
	int e[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			e[i][j] = a[i] % 13;
			a[i] /= 13;
		}
	}
	printf("#");
	for (int i = 0; i < 3; i++) 
		for (int j = 1; j>=0; j--) 
			printf("%c", d[e[i][j]]);
	system("pause");
	return 0;
}