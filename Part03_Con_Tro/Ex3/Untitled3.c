//**Bài 3: Truy cập mảng bằng con trỏ**
//•	Yêu cầu: Viết chương trình khai báo mảng int với 5 phần tử, dùng con trỏ để truy cập và in từng phần tử thay vì dùng chỉ số (arr[i]).
//•	Hướng dẫn: 
//o	Chạy và kiểm tra đầu ra (1 2 3 4 5).
//o	Thử thay đổi một phần tử qua con trỏ (ví dụ: *(ptr + 2) = 10;) và in lại mảng.


#include<stdio.h>
int main(){
	int arr[5]={1, 2, 3, 4, 5};
	int *ptr = arr;
	for(int i = 0; i < 5; i++){
		printf("%d ", *(ptr + i));
	}
	printf("\n");
	return 0;
}
