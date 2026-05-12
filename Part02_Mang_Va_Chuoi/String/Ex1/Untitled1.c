
// **1.In chuỗi** 
// ```
// o	Yêu cầu: Nhập chuỗi từ bàn phím và in ra màn hình.
// o	Output mẫu: 
// Nhap chuoi: hello
// Chuoi: hello
// ```
#include<stdio.h>
#include <string.h>
int main(){
	char chuoi[7];
	printf("Nhap chuoi: ");
	fgets(chuoi, sizeof(chuoi), stdin);
	printf("Chuoi: %s\n",chuoi);
	return 0;
}
