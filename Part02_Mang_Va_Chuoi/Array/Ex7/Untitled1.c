#include<stdio.h>

int main(){
	int n;
	printf("Nhap kich thuoc mang: ");
	if(scanf("%d",&n) != 1 || n < 0 || n > 1000){
		printf("Loi: Nhap kich thuoc mang sai!\n");
		return 1;
	}
	
	int arr[n];
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		if(scanf("%d",&arr[i]) != 1){
			printf("Loi: Nhap phan tu mang sai!\n");
			return 1;
		}
	}
	
	int pos;
	printf("Nhap vi tri can xoa: ");
	if(scanf("%d",&pos) != 1 || pos < 0 || pos >= n){
		printf("Loi: Vi tri khong hop le!\n");
		return 1;
	}
	for(int i = pos; i < n-1; i++){
		arr[i] = arr[i+1];
	}
	
	n--;
	
	printf("Mang sau khi xoa: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

