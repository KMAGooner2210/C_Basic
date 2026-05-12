// **Bài 6.Sắp xếp mảng**

// o	Yêu cầu: Viết chương trình nhập mảng số nguyên với kích thước n nhập từ bàn phím. Thực hiện sắp xếp mảng theo thứ tự tăng dần và giảm dần bằng cách sử dụng hàm qsort trong thư viện <stdlib.h>. In mảng ban đầu và kết quả sau khi sắp xếp ra màn hình.

// o	Output mẫu: 

//       Nhap so luong phan tu: 5
//       Nhap 5 so nguyen:
//       arr[0]: 5
//       arr[1]: 2
//       arr[2]: 8
//       arr[3]: 1
//       arr[4]: 9
      
//       --- Mang ban dau ---
//       5 2 8 1 9 
      
//       --- Sap xep tang dan ---
//       1 2 5 8 9 
      
//       --- Sap xep giam dan ---
//       9 8 5 2 1


#include <stdio.h>
#include <stdlib.h>

int compareTang(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int compareGiam(const void *a, const void *b){
	return (*(int*)b - *(int*)a);
}

void xuatMang(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int n;

	printf("Nhap so luong phan tu: ");
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("Kich thuoc khong hop le!\n");
		return 1;
	}

	int *arr =(int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Cap phat bo nho khong hop le!\n");
		return 1;
	}

	printf("Nhap %d so nguyen:\n", n);
	for(int i = 0; i < n; i++){
		printf("arr[%d]: ", i);
		if(scanf("%d", &arr[i]) != 1){
			printf("Nhap sai!\n");
			free(arr);
			return 1;
		}
	}

	printf("\n--- Mang ban dau ---\n");
	xuatMang(arr, n);

	qsort(arr, n, sizeof(int), compareTang);
	printf("\n--- Sap xep tang dan ---\n");
	xuatMang(arr,n);

	qsort(arr, n, sizeof(int), compareGiam);
	printf("\n--- Sap xep giam dan ---\n");
	xuatMang(arr,n);

	free(arr);
	return 0;
}
