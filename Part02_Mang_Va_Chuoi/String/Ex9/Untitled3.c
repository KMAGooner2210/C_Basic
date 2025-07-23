#include<stdio.h>
#include<string.h>

void removeChar(char str[], char ch){
	int i, j = 0;
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] != ch){
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
}

int main(){
	char str[100];
	char ch;
	printf("Nhap chuoi: ");
	fgets(str,sizeof(str),stdin);
	
	if(str[strlen(str) - 1] == '\n'){
		str[strlen(str) - 1] = '\0';
	}
	
	printf("Nhap ky tu can xoa: ");
	scanf(" %c",&ch);
	removeChar(str, ch);
	printf("Chuoi sau khi xoa: %s",str);
	return 0;
}

