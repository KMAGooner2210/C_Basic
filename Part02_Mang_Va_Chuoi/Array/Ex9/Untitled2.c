#include <stdio.h>
#define MAX_SIZE 100

int  main(){
	int arr[MAX_SIZE];
	int n, target;
	
	printf("Nhap kich thuoc mang: ");
	if(scanf("%d", &n) != 1 || n < 0 || n > MAX_SIZE){
		printf("Kich thuoc khong hop le!\n");
		return 1;
	}
	
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Nhap gia tri can tim: ");
	scanf("%d", &target);
	
	int index = -1;
	for(int i = 0; i < n; i++){
		if(arr[i] == target){
			index = i;
			break;
		}
	}
	
	printf("Vi tri: %d\n", index);
	return 0;
}
