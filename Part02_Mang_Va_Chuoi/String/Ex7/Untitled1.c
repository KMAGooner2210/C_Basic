#include<stdio.h>
#include<string.h>

void toUpperCase(char str[]){
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			str[i] = str[i] - 32;
		}
	}
}

void toLowerCase(char str[]){
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str[i] + 32;
		}
	}
}

int main(){
	char str[100];
	
	printf("Nhap chuoi: ");
	fgets(str, sizeof(str), stdin);
	
	if(str[strlen(str) - 1] == '\n'){
		str[strlen(str) - 1] = '\0';
	}
	
	char upperStr[100], lowerStr[100];
	strcpy(upperStr, str);
	strcpy(lowerStr, str);
	
	toUpperCase(upperStr);
	toLowerCase(lowerStr);
	
	printf("Chuoi chu hoa: %s\n", upperStr);
	printf("Chuoi chu thuong: %s\n", lowerStr);
	
	return 0;
}
