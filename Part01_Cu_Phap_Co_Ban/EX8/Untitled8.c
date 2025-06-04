	#include <stdio.h>
	int main() {
	    int score;
	    printf("Nhap diem (0-10): ");
	    scanf("%d", &score);
	    switch(score) {
	        case 10:
	        case 9:
	        case 8: printf("Xep loai A\n"); break;
	        case 7:
	        case 6: printf("Xep loai B\n"); break;
	        case 5:
	        case 4: printf("Xep loai C\n"); break;
	        default: printf("Xep loai D\n");
	    }
	    return 0;
}

