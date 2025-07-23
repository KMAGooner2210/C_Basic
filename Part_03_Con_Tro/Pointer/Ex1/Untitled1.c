#include<stdio.h>
int main(){
	int x = 10;
	int *ptr = &x;
	printf("Dia chi cua bien x la: %p\n",(void *)&x);
	printf("Gia tri cua bien x qua ptr: %d\n", *ptr);
	printf("Dia chi cua con tro ptr la: %p\n", (void*)&ptr);
	return 0;
}
