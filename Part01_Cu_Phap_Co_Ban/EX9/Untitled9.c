	#include <stdio.h>
	int main() {
	    int age;
	    float income;
	    printf("Nhap tuoi: ");
	    scanf("%d", &age);
	    printf("Nhap thu nhap (trieu): ");
	    scanf("%f", &income);
	    if(age >= 18 && income >= 20) {
	        printf("Du dieu kien vay von\n");
	    } else {
	        printf("Khong du dieu kien\n");
	    }
	    return 0;
}

