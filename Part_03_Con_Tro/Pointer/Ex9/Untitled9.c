#include<stdio.h>
int main(){
	int x = 10;
	int *ptr = &x;
	int **pptr = &ptr;
	printf("Gia tri cua bien x thong qua **pptr: %d\n", **pptr);  //In:10
	printf("Gia tri cua ptr thong qua *pptr: %d\n", (void*)*pptr); // In: 0x1000 (dia chi cua x)
	printf("Dia chi cua ptr thong qua pptr: %p\n", (void*)pptr);
	return 0;
}
