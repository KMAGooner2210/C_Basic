#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	printf("Nhap kich thuoc mang: ");
	scanf("%d", &n);
	
	if(n <= 0){
		printf("Kich thuong mang khong hop le!\n");
		return 1;
	}
	
	int *arr = calloc(n, sizeof(int));
	if(arr == NULL){
		printf("Loi cap phat bo nho!\n");
		return 1;
	}

	printf("Mang sau khi cap phat bang calloc: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	free(arr);
	arr = NULL;
	return 0;
}
