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


	float sum = 0.0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
	}

	float average = sum / n;
	printf("Trung binh mang : %.2f\n", average);
	free(arr);
	return 0;
}