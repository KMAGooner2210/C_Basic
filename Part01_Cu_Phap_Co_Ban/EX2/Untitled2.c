#include <stdio.h>

int main() {
    float length, width, perimeter, area;

    printf("Nhap chieu dai: ");
    scanf("%f", &length);
    printf("Nhap chieu rong: ");
    scanf("%f", &width);

    perimeter = 2 * (length + width);
    area = length * width;

    printf("Chu vi hinh chu nhat: %.2f\n", perimeter);
    printf("Dien tich hinh chu nhat: %.2f\n", area);

    return 0;
}
