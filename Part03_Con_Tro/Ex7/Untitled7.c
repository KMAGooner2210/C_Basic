//**Bài 7: Cấp phát bộ nhớ động bằng con trỏ** 
//Yêu cầu: Viết chương trình cấp phát bộ nhớ động cho một biến int, gán giá trị, in giá trị, sau đó giải phóng bộ nhớ.
//•	Hướng dẫn: 
//o	Chạy và kiểm tra kết quả (Giá trị: 50).
//o	Thử không gọi free(ptr) và giải thích tại sao điều này gây rò rỉ bộ nhớ.

#include<stdio.h>
int main(){
	int *ptr = malloc(sizeof(int));
	if(ptr == NULL){
		printf("Cap phat that bai!\n");
		return 1;
	}
	*ptr =  50;
	printf("Gia tri: %d\n", *ptr);
	free(ptr);
	return 0;
}
