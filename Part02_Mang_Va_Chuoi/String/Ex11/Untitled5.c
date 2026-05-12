// **11.Tìm chuỗi con** 
// ```
// o	Yêu cầu: Nhập chuỗi lớn và chuỗi con, tìm vị trí đầu tiên của chuỗi con trong chuỗi lớn (dùng strstr hoặc thủ công).
// o	Output mẫu: 
// Nhap chuoi lon: hello world
// Nhap chuoi con: world
// Vi tri: 6

#include<stdio.h>
#include<string.h>

int main(){
	char str[100], substr[100];
	printf("Nhap chuoi lon: ");
	fgets(str,sizeof(str),stdin);
	if(str[strlen(str) - 1] == '\n'){
		str[strlen(str) - 1] = '\0';
	}
	
	printf("Nhap chuoi con: ");
	fgets(substr,sizeof(substr),stdin);
	if(substr[strlen(substr) - 1] == '\n'){
		substr[strlen(substr) - 1] = '\0';
	}
	
	char *pos = strstr(str,substr);
	if(pos != NULL){
		int index = pos - str;
		printf("Vi tri: %d\n",index);
	}else{
		printf("Chuoi con khong tim thay!\n");
	}
	return 0;
	}
	
