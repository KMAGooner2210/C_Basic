//**Bài 1: In địa chỉ và giá trị của biến qua con trỏ**
//•	Yêu cầu: Viết chương trình khai báo một biến kiểu int, một con trỏ trỏ tới biến đó, sau đó in: 
//o	Địa chỉ của biến.
//o	Giá trị của biến qua con trỏ.
//o	Địa chỉ của chính con trỏ.
//•	Hướng dẫn: 
//o	Chạy chương trình và quan sát đầu ra.
//o	Thử thay đổi giá trị của x qua *ptr (ví dụ: *ptr = 20;) và in lại x để kiểm tra.


#include<stdio.h>
int main(){
	int x = 10;
	int *ptr = &x;
	printf("Dia chi cua bien x la: %p\n",(void *)&x);
	printf("Gia tri cua bien x qua ptr: %d\n", *ptr);
	printf("Dia chi cua con tro ptr la: %p\n", (void*)&ptr);
	return 0;
}
