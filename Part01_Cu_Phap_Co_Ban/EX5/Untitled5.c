#include <stdio.h>

int square(int n) {
    return n * n;
}

int main() {
    int number;

    printf("Nhap mot so nguyen: ");
    scanf("%d", &number);

    int result = square(number);
    printf("Binh phuong cua %d la: %d\n", number, result);

    return 0;
}
