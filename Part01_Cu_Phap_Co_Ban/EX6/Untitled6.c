#include <stdio.h>
int main() {
int n, sum = 0, i = 1;
printf("Nhap n: ");
scanf("%d", &n);
while(i <= n) {
sum += i;
i++;
}
printf("Tong tu 1 den %d: %d\n", n, sum);
return 0;
}

