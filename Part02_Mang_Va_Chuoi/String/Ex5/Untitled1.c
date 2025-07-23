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
