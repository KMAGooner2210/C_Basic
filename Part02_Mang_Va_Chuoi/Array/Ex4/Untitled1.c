#include<stdio.h>

int main(){
	int arr[100], n;
	
	printf("Nhap kich thuoc mang: ");
	scanf("%d",&n);
	
	if(n < 0 || n > 100){
		printf("Kich thuoc mang khong hop le!\n");
		return 1;
	}
	
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Mang dao nguoc: ");
	for(int i = n-1; i >= 0; i--){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
