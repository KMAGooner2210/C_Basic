#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Nhap kich thuoc mang: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Kich thuoc mang khong hop le!\n");
        return 1;
    }


    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }


    printf("Nhap mang:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Nhap sai dinh dang so!\n");
            free(arr); 
            return 1;
        }
    }


    int pos;
    printf("Nhap vi tri can xoa: "); 
    if (scanf("%d", &pos) != 1 || pos < 0 || pos >= n) {
        printf("Loi: Vi tri khong hop le!\n");
        free(arr);
        return 1;
    }

    
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; 

    printf("Mang sau khi xoa: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    free(arr);
    return 0;
}