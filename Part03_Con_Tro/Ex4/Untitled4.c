//**Bài 4: In từng ký tự của chuỗi bằng con trỏ**
//•	Yêu cầu: Viết chương trình khai báo chuỗi (dùng mảng ký tự hoặc chuỗi hằng), dùng con trỏ để in từng ký tự của chuỗi.
//•	Mã nguồn mẫu: 
//•	Hướng dẫn: 
//o	Chạy và kiểm tra đầu ra (H e l l o).
//o	Thử sửa đổi một ký tự (ví dụ: *ptr = 'h'; với str[]) và in lại chuỗi.
//o	Thử dùng chuỗi hằng (char *str = "Hello";) và giải thích tại sao không sửa được.

#include<stdio.h>
int main(){
	char str[]="Gooner";
	char *ptr = str;
	while(*ptr != '\0'){
		printf("%c ", *ptr);
		ptr++;
	}
	printf("\n");
	return 0;
}
