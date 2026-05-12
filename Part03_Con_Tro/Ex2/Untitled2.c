//**Bài 2: Hoán đổi hai số bằng con trỏ**
//•	Yêu cầu: Viết hàm swap(int *a, int *b) để hoán đổi giá trị của hai biến, gọi hàm trong main và in kết quả.
//•	Hướng dẫn: 
//o	Chạy và kiểm tra kết quả (x = 10, y = 5).
//o	Thử viết lại hàm swap mà không dùng con trỏ (pass-by-value) và giải thích tại sao không hoán đổi được.

#include<stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int x = 5, y = 10;
	printf("Truoc swap: x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("Sau swap: x = %d, y = %d\n", x, y);
	return 0;
}
