#include<stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int x = 5, y = 10;
	printf("Truoc swap: x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("Sau swap: x = %d, y = %d\n", x, y);
	return 0;
}
