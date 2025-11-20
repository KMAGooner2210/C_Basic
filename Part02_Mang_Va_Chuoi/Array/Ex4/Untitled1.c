#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	printf("Nhap kich thuoc mang: ");
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("Kich thuoc mang khong hop le!\n");
		return 1;
	}

	int *arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Cap phat bo nho khong hop le!\n");
		free(arr);
		return 1;
	}

	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		if(scanf("%d", &arr[i]) != 1){
			printf("Nhap sai!\n");
			return 1;
		}
	}

	printf("Mang dao nguoc: ");
	for(int i = n - 1; i >= 0 ; i--){
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}