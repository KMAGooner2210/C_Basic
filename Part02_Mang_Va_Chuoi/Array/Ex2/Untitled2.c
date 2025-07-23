#include<stdio.h>
int main(){
	int n, arr[100];
	int sum = 0;
	
	printf("Nhap kich thuoc mang: ");
	scanf("%d", &n);
	
	if(n < 0 || n > 100){
		printf("Kich thuoc mang khong hop le!\n");
		return 1;
	}
	
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("Tong mang: %d\n",sum);
	printf("\n");
	return 0;
}
