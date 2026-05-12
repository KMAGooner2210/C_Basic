
// **Bài 8.Chèn phần tử**

// o	Yêu cầu: Nhập mảng số nguyên, vị trí và giá trị cần chèn, chèn phần tử vào vị trí đó và in mảng mới.

// o	Output mẫu: 

//     Nhap kich thuoc mang: 5
//     Nhap mang: 1 2 3 4 5
//     Nhap vi tri chen: 2
//     Nhap gia tri chen: 10
//     Mang sau khi chen: 1 2 10 3 4 5

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, pos, value;

	printf("Nhap kich thuoc mang ban dau: ");
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("Kich thuoc khong hop le!\n");
		return 1;
	}

	int *arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Cap phat bo nho khong hop le!\n");
		return 1;
	}

	printf("Nhap %d phan tu:\n", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	printf("Nhap vi tri can chen (0 - %d): ", n);
	if(scanf("%d", &pos) != 1 || pos < 0 || pos >= n){
		printf("Vi trỉ chen khong hop le!\n");
		free(arr);
		return 1;
	}

	printf("Nhap gia tri muon chen: ");
	scanf("%d", &value);

	int *temp = (int*)realloc(arr, (n + 1) * sizeof(int));

	if(temp == NULL){
		printf("Khong the noi rong bo nho!\n");
		free(arr);
		return 1;
	} else {
		arr = temp;
	}

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

	free(arr);
	return 0;
}
