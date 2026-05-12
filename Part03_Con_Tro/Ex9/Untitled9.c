//**Bài 9: Sử dụng con trỏ đến con trỏ** 
//•	Yêu cầu: Khai báo một con trỏ đến con trỏ (int**), in giá trị của biến gốc và địa chỉ của con trỏ cấp một.
//•	Hướng dẫn: 
//o	Chạy và kiểm tra đầu ra.
//o	Thử thay đổi giá trị x qua **pptr (ví dụ: **pptr = 100;) và in lại x.


#include<stdio.h>
int main(){
	int x = 10;
	int *ptr = &x;
	int **pptr = &ptr;
	printf("Gia tri cua bien x thong qua **pptr: %d\n", **pptr);  //In:10
	printf("Gia tri cua ptr thong qua *pptr: %d\n", (void*)*pptr); // In: 0x1000 (dia chi cua x)
	printf("Dia chi cua ptr thong qua pptr: %p\n", (void*)pptr);
	return 0;
}
