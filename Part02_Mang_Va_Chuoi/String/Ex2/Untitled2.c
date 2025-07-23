#include<stdio.h>
#include <string.h>
int main(){
	char chuoi[100];
	printf("Nhap chuoi: ");
	fgets(chuoi, sizeof(chuoi), stdin);
	int i = 0;
    while (chuoi[i] != '\0') {
        if (chuoi[i] == '\n') {
            chuoi[i] = '\0';
            break;
        }
        i++;
    }
	printf("Do dai chuoi: %d\n",strlen(chuoi));
	return 0;
}
