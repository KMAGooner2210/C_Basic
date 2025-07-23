#include<stdio.h>
#include <string.h>
int main(){
	char chuoi1[100], chuoi2[100];
	printf("Nhap chuoi 1: ");
	fgets(chuoi1,sizeof(chuoi1),stdin);
	chuoi1[strcspn(chuoi1,"\n")] = '\0';
	
	printf("Nhap chuoi 2: ");
	fgets(chuoi2,sizeof(chuoi2),stdin);
	chuoi2[strcspn(chuoi2, "\n")] = '\0';
	
	if(strcmp(chuoi1, chuoi2) == 0){
		printf("Hai chuoi giong nhau.\n");
	}else{
		printf("Hai chuoi khac nhau.\n");
	}
	return 0;
}
