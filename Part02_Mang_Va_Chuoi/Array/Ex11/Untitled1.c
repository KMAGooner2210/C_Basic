#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2;

    int *arr1 = NULL, *arr2 = NULL, *merged = NULL;


    printf("Nhap kich thuoc mang 1: ");
    if (scanf("%d", &n1) != 1 || n1 <= 0) { 
        printf("Kich thuoc khong hop le!\n");
        return 1;
    }

    arr1 = (int*)malloc(n1 * sizeof(int));
    if (arr1 == NULL) {
        printf("Cap phat bo nho mang 1 that bai!\n");
        return 1;
    }

    printf("Nhap mang 1:\n"); 
    for (int i = 0; i < n1; i++) {
        if (scanf("%d", &arr1[i]) != 1) {
            printf("Nhap sai!\n");
            free(arr1); 
            return 1;
        }
    }


    printf("Nhap kich thuoc mang 2: ");
    if (scanf("%d", &n2) != 1 || n2 <= 0) {
        printf("Kich thuoc khong hop le!\n");
        free(arr1); 
        return 1;
    }

    arr2 = (int*)malloc(n2 * sizeof(int));
    if (arr2 == NULL) {
        printf("Cap phat bo nho mang 2 that bai!\n");
        free(arr1);
        return 1;
    }

    printf("Nhap mang 2:\n");
    for (int i = 0; i < n2; i++) {
        if (scanf("%d", &arr2[i]) != 1) {
            printf("Nhap sai!\n");
            free(arr2);
            free(arr1); 
            return 1;
        }
    }


    merged = (int*)malloc((n1 + n2) * sizeof(int));
    if (merged == NULL) {
        printf("Cap phat bo nho mang merged that bai!\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    while (j < n2) {
        merged[k++] = arr2[j++];
    }


    printf("Mang hop nhat: ");
    for (int x = 0; x < n1 + n2; x++) {
        printf("%d ", merged[x]);
    }
    printf("\n");

 
    free(arr1);
    free(arr2);
    free(merged);

    return 0;
}