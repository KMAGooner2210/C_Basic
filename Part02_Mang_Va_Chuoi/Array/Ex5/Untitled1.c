// **Bài 5.Tìm số lớn nhất/nhỏ nhất**

// o	Yêu cầu: Nhập mảng số nguyên, tìm và in giá trị lớn nhất và nhỏ nhất.

// o	Output mẫu: 

//         Nhap kich thuoc mang: 5
//         Nhap mang: 3 1 4 1 5
//         So lon nhat: 5
//         So nho nhat: 1

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int main(){
	int n;

	printf("Nhap kich thuoc mang:");
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("Kich thuoc sai!\n");
		return 1;
	}

	int *arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Cap phat khong hop le!\n");
		return 1;
	}

	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		if(scanf("%d", &arr[i]) != 1){
			printf("Nhap sai!\n");
			return 1;
		}
	}
	int max_value = INT_MIN;
	int min_value = INT_MAX;
	for(int i = 0; i < n; i++){
		if(arr[i] > max_value){
			max_value = arr[i];
		}
		if(arr[i] < min_value){
			min_value = arr[i];
		}
	}

	printf("So lon nhat: %d\n", max_value);
	printf("So nho nhat: %d\n", min_value);

	return 0;
	}
