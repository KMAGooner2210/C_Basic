#include<stdio.h>
#define MAX_SIZE 100
int main(){
	int  arr[MAX_SIZE], result[MAX_SIZE];
	int n, reCount = 0;
	printf("Nhap kich thuoc mang: ");
	if(scanf("%d",&n) != 1 || n < 0 || n > MAX_SIZE){
		printf("Kich thuoc mang khong hop le!\n");
		return 1;
	}
	
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		if(scanf("%d",&arr[i]) != 1){
			printf("Gia tri khong hop le!\n");
			return 1;
		}
	}
	
	for(int i = 0; i < n; i++){
		int isDup = 0;
		
		for(int j = 0; j < reCount;j++){
			if(arr[i] == result[j]){
				isDup = 1;
				break;
			}
		}
		
		//Khong trung them vao mang result
		if(!isDup){
			result[reCount] = arr[i];
			reCount++;
		}
	}
	
	printf("Mang sau khi xoa phan tu trung lap: ");
	for(int i = 0; i < reCount; i++){
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
	
