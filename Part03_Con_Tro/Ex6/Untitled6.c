//**Bài 6: Sao chép chuỗi bằng con trỏ** 
//•	Yêu cầu: Viết hàm sao chép chuỗi bằng con trỏ, không dùng strcpy.
//•	Hướng dẫn: 
//o	Chạy và kiểm tra kết quả (Chuỗi sao chép: Hello).
//Thử sao chép chuỗi dài hơn (nhưng đảm bảo dest đủ lớn).

#include<stdio.h>
void copy_string(char *dest, const char *src){
	while(*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
int main(){
	char src[] = "Hello";
	char dest[10];
	copy_string(dest, src);
	printf("Chuoi sao chep: %s\n",dest);
	return 0;
}
