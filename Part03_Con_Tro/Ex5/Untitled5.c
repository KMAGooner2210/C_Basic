//**Bài 5: Tính tổng các phần tử mảng bằng con trỏ**
//•	Yêu cầu: Viết chương trình khai báo mảng int với 5 phần tử, dùng con trỏ để tính và in tổng các phần tử.
//•	Hướng dẫn: 
//o	Chạy và kiểm tra kết quả (Tổng: 15).
//o	Thử thay đổi giá trị mảng và tính lại tổng.

#include<stdio.h>
int main(){
	int arr[5]= {1, 2, 3, 4, 5};
	int *ptr = arr;
	int sum = 0;
	for(int i = 0; i < 5; i++){
		sum += *(ptr + i);
	}
	printf("Tong: %d\n", sum);
	return 0;
}
