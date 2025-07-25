#include <stdio.h>
int main() {
    int *ptr = NULL;
    if (ptr == NULL) {
        printf("Con tro NULL, khong the truy cap!\n");
    } else {
        printf("Gia tri: %d\n", *ptr);
    }
    return 0;
}
