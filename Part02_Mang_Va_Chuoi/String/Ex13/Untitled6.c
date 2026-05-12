// **13.Tách chuỗi** 
// ```  
// o	Yêu cầu: Nhập chuỗi, tách thành các từ dựa trên dấu phân cách (ví dụ: khoảng trắng).
// o	Output mẫu: 
// Nhap chuoi: hello world everyone
// Cac tu: 
// 1. hello
// 2. world
// 3. everyone

#include<stdio.h>
#include<string.h>

void splitString(char str[]){
	int count = 0;
	char *token = strtok(str, " ");
	
	printf("Cac tu:\n");
	while(token != NULL){
		printf("%d. %s\n", ++count, token);
		token = strtok(NULL, " ");
	}
}

int main(){
	char str[100];
	printf("Nhap chuoi: ");
	fgets(str,sizeof(str),stdin);
	if(str[strlen(str) - 1] == '\n'){
		str[strlen(str) - 1] = '\0';
	}
	splitString(str);
	return 0;
	}

