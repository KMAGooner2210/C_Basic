#include<stdio.h>
#include<string.h>
int main(){
	int len ;
	char chuoi[100];
	printf("Nhap chuoi : ");
	fgets(chuoi,sizeof(chuoi),stdin);
	chuoi[strcspn(chuoi,"\n")] = '\0';
	
	len = strlen(chuoi);
	for(int i =0; i < len/2; i++){
		char temp = chuoi[i];
		chuoi[i] = chuoi[len - 1 - i];
		chuoi[len - 1 - i] = temp;
	}
	
	printf("Chuoi dao nguoc: %s\n", chuoi);
	return 0;
}
