#include<stdio.h>

int main(){
	int n;
	printf("Nhap kich thuoc mang: ");
	if(scanf("%d",&n) != 1 || n<= 0 || n > 1000){
		printf("Loi: Kich thuoc mang!\n");
		return 1;
	}
	
	int arr[n];
	
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		if(scanf("%d", &arr[i]) != 1){
			printf("Loi: Phan tu mang bi nhap sai!\n");
			return 1;
		}
	}
	
	for(int i = 0; i < n-1; i++){
		int swapped = 0;
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapped = 1;
			}
		}
		if(swapped = 0) break;
	}
	
	printf("Mang sau khi sap xep: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
	

