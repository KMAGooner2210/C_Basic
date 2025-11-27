#include <stdio.h>
#include <stdlib.h>

int compareTang(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int compareGiam(const void *a, const void *b){
	return (*(int*)b - *(int*)a);
}

void xuatMang(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int n;

	printf("Nhap so luong phan tu: ");
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("Kich thuoc khong hop le!\n");
		return 1;
	}

	int *arr =(int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Cap phat bo nho khong hop le!\n");
		return 1;
	}

	printf("Nhap %d so nguyen:\n", n);
	for(int i = 0; i < n; i++){
		printf("arr[%d]: ", i);
		if(scanf("%d", &arr[i]) != 1){
			printf("Nhap sai!\n");
			free(arr);
			return 1;
		}
	}

	printf("\n--- Mang ban dau ---\n");
	xuatMang(arr, n);

	qsort(arr, n, sizeof(int), compareTang);
	printf("\n--- Sap xep tang dan ---\n");
	xuatMang(arr,n);

	qsort(arr, n, sizeof(int), compareGiam);
	printf("\n--- Sap xep giam dan ---\n");
	xuatMang(arr,n);

	free(arr);
	return 0;
}