#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int * arr = NULL;

	printf("Nhap kich thuoc mang: ");
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("Kich thuoc khong hop le!");
		return 1;
	}

	arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Loi: Khong du bo nho!");
		return 1;
	}

	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		if(scanf("%d", &arr[i]) != 1){
			printf("Nhap sai!\n");
			free(arr);
			return 1;
		}
	}

	printf("Mang: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	free(arr);
	return 0;

}