// **5.Sao chép chuỗi**
// ``` 
// o	Yêu cầu: Nhập chuỗi, sao chép sang chuỗi khác bằng strcpy và in kết quả.
// o	Output mẫu: 
// Nhap chuoi: hello
// Chuoi sao chep: hello

#include<stdio.h>
#include<string.h>
int main(){
	char chuoi1[100], chuoi2[100];
	printf("Nhap chuoi 1: ");
	fgets(chuoi1,sizeof(chuoi1),stdin);
	chuoi1[strcspn(chuoi1, "\n")] = '\0';
	
	strcpy(chuoi2, chuoi1);
	printf("Chuoi sao chep: %s\n", chuoi2);
	return 0;
 }
