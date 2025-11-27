#include <stdio.h>
#include <stdlib.h>

int  main(){
	int n, target;
	
	printf("Nhap kich thuoc mang: ");
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("Kich thuoc khong hop le!\n");
		return 1;
	}

	int *arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Cap phat bo nho khong hop le!\n");
		return 1;
	}
	
	printf("Nhap mang:\n");
	for(int i = 0; i < n; i++){
		if(scanf("%d", &arr[i]) != 1){
			printf("Nhap sai!\n");
			free(arr);
			return 1;
		}
	}
	
	printf("Nhap gia tri can tim: ");
	if(scanf("%d", &target) != 1){
		printf("Nhap sai!\n");
		free(arr);
		return 1;
	}
	
	int index = -1;
	for(int i = 0; i < n; i++){
		if(arr[i] == target){
			index = i;
			break;
		}
	}
	
    if (index != -1) {
        printf("Tim thay gia tri %d tai vi tri (index): %d\n", target, index);
    } else {
        printf("Khong tim thay gia tri %d trong mang.\n", target);
    }
}
