#include <stdio.h>
#define MAX_SIZE 100
int main(){
	int arr[MAX_SIZE];
	int n, pos, value;
	
	printf("Nhap kich thuoc mang: ");
	if(scanf("%d",&n) != 1 || n < 0 || n > MAX_SIZE){
		printf("Kich thuoc khong hop le!\n");
		return 1;
	}
	
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Nhap vi tri chen: ");
	if(scanf("%d", &pos) != 1 || pos < 0 || pos > n){
		printf("Vi tri chen khong hop le!\n");
		return 1;
	}
	printf("Nhap gia tri chen: ");
	scanf("%d", &value);
	
	for(int i = n; i > pos; i--){
		arr[i] = arr[i-1];
	}
	arr[pos] = value;
	n++;
	
	printf("Mang sau khi chen: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
	
}
