#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int * arr;

	printf("Nhap kich thuoc mang: ");
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("Kich thuoc khong hop le!\n");
		return 1;
	}

	arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Loi: Bo nho khong hop le!\n");
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

	printf("\n");
	
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
	}
	printf("Tong mang: %d\n", sum);

	free(arr);
	return 0;
}
