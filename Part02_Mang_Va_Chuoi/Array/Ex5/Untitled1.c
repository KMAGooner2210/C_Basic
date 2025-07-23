#include<stdio.h>

int main(){
	int n;
	
	printf("Nhap kich thuoc mang: ");
	if (scanf("%d", &n) != 1) {
        printf("Loi: Kich thuoc mang phai la so nguyen!\n");
        return 1;
    }
    
   
    if (n <= 0) {
        printf("Loi: Kich thuoc mang phai lon hon 0!\n");
        return 1;
    }
	
	int arr[n];
	
    printf("Nhap mang: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Loi: Phai nhap so nguyen cho phan tu mang!\n");
            return 1;
        }
    }
	
	int max = arr[0];
	int min = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > max){
			max = arr[i];
		}
		if(arr[i] < min){
			min = arr[i];
		}
	}
	
	printf("Max: %d\n", max);
	printf("Min: %d\n", min);
	
	return 0;
}
