#include<stdio.h>
void copy_string(char *dest, const char *src){
	while(*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
int main(){
	char src[] = "Hello";
	char dest[10];
	copy_string(dest, src);
	printf("Chuoi sao chep: %s\n",dest);
	return 0;
}
