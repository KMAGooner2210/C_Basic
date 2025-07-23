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
	
