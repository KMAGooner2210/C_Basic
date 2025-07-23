#include <stdio.h>
#define MAX_SIZE 100

int main(){
	int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[MAX_SIZE * 2];
	int n1, n2;
	
	printf("Nhap kich thuoc mang 1: ");
	if(scanf("%d",&n1) != 1 || n1 < 0 || n1 > MAX_SIZE){
		printf("Kich thuoc khong hop le!\n");
		return 1;
	}
	
	printf("Nhap mang 1: ");
	for(int i = 0; i < n1; i++){
		scanf("%d", &arr1[i]);
	}
	
	printf("Nhap kich thuoc mang 2: ");
	if(scanf("%d",&n2) != 1 || n2 < 0 || n2 > MAX_SIZE){
		printf("Kich thuoc khong hop le!\n");
		return 1;
	}
	
	printf("Nhap mang 2: ");
	for(int i = 0; i < n2; i++){
		scanf("%d", &arr2[i]);
	}
	
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2){
		if (arr1[i] <= arr2[j]){
			merged[k] = arr1[i];
			i++;
		} else{
			merged[k] = arr2[j];
			j++;
		}
		k++;
	}
	
	while(i < n1){
		merged[k] = arr1[i];
		i++;
		k++;
	}
	
	while(j < n2){
		merged[k] = arr2[j];
		j++;
		k++;
	}
	
	printf("Mang hop nhat: ");
	for(int i = 0; i < n1 + n2; i++){
		printf("%d ", merged[i]);
	}
	printf("\n");
	return 0;
}
