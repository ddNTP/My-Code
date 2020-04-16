#include<iostream>
#include<algorithm>
int main() {
	float a[3],b[3];
	char c[3];
	char d[3] = {'W','T','L' };
	for (int i = 0; i < 3; i++) {
		scanf("%f%f%f", &a[0], &a[1], &a[2]);
		float tmp = a[0];
		int tmp1 = 0;
		for (int j = 1; j < 3; j++) {
			if (a[j] > tmp) {
				tmp = a[j];
				tmp1 = j;
			}
		}
		b[i] = tmp;
		c[i] = d[tmp1];
	}
	for (int i = 0; i < 3; i++)
		printf("%c ", c[i]);
	printf("%.2f", (b[0] * b[1] * b[2] * 0.65 - 1) * 2);
	return 0;
}