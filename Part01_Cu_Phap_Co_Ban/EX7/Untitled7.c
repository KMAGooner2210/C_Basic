#include <stdio.h>
int main() {
	int n, i = 2, isPrime = 1;
	printf("Nhap so: ");
	scanf("%d", &n);
	if(n < 2) isPrime = 0;
	else {
		do {
			if(n % i == 0) {
				isPrime = 0;
				break;
				}
			i++;
		} while(i <= n / 2);
	}
	printf("%d %s so nguyen to\n", n, isPrime ? "la" : "khong phai");
	return 0;
}

