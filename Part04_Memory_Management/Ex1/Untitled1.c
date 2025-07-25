#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	printf("Nhap kich thuoc mang: ");
	scanf("%d", &n);
	
	if(n<=0){
	printf("Kich thuoc mang khong hop le!\n");
	return 1;
	}
	
	int *arr = malloc(sizeof(int) * n);
	if(arr == NULL){
		printf("Loi cap phat bo nho\n");
		return 1;
	}
	
	printf("Nhap %d phan tu :\n", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Mang vua nhap: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	free(arr);
	arr = NULL;
	return 0;
}
	
