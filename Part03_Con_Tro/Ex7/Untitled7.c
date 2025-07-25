#include<stdio.h>
int main(){
	int *ptr = malloc(sizeof(int));
	if(ptr == NULL){
		printf("Cap phat that bai!\n");
		return 1;
	}
	*ptr =  50;
	printf("Gia tri: %d\n", *ptr);
	free(ptr);
	return 0;
}
