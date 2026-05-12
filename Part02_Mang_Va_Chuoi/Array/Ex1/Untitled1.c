// * **Bài 1: Nhập và in mảng số nguyên**

//   o Yêu cầu:
  
//         Viết chương trình nhập vào kích thước mảng n và các phần tử của mảng số nguyên từ bàn phím
     
//         In ra mảng vừa nhập

//   o Mô tả chi tiết:
  
//         Nhập kích thước mảng n (số nguyên dương)
     
//         Nhập n phần tử của mảng số nguyên

//         In ra tất cả các phần tử của mảng
  
//   o Input mẫu:
  
//         5
//         1 2 3 4 5

//   o Output mẫu:
  
//         Nhap kich thuoc mang: 5
//         Nhap mang: 1 2 3 4 5
//         Mang: 1 2 3 4 5


#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int * arr = NULL;

	printf("Nhap kich thuoc mang: ");
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("Kich thuoc khong hop le!");
		return 1;
	}

	arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Loi: Khong du bo nho!");
		return 1;
	}

	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		if(scanf("%d", &arr[i]) != 1){
			printf("Nhap sai!\n");
			free(arr);
			return 1;
		}
	}

	printf("Mang: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	free(arr);
	return 0;

}
