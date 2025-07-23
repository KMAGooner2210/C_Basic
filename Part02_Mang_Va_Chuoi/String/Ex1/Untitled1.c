#include<stdio.h>
#include <string.h>
int main(){
	char chuoi[7];
	printf("Nhap chuoi: ");
	fgets(chuoi, sizeof(chuoi), stdin);
	printf("Chuoi: %s\n",chuoi);
	return 0;
}
