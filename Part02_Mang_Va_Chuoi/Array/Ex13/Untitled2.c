#include<stdio.h>
#define MAX_SIZE 100
int main(){
	int arr[MAX_SIZE], length[MAX_SIZE], prev[MAX_SIZE];
	int n, maxLen = 0, maxIndex = 0;
	
	printf("Nhap kich thuoc mang: ");
	if(scanf("%d",&n) != 1 || n < 0 || n > MAX_SIZE){
		printf("Kich thuoc mang khong hop le!\n");
		return 1;
	}
	
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++){
		if(scanf("%d", &arr[i]) != 1) {
			printf("Gia tri khong hop le!\n");
			return 1;
		}
	}
	
	for(int i = 0; i < n; i++){
		length[i] = 1;
		prev[i] = -1;
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] && length[j] + 1 > length[i]){
				length[i] = length[j] + 1; // C?p nh?t d? dài
                prev[i] = j;               // Luu ch? s? ph?n t? tru?c
            }
        }
        // C?p nh?t d? dài l?n nh?t và ch? s?
        if (length[i] > maxLen) {
            maxLen = length[i];
            maxIndex = i;
        }
    }

    // Khôi ph?c dãy con tang dài nh?t
    int lis[MAX_SIZE], lisCount = 0;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        lis[lisCount++] = arr[i];
        if (prev[i] == -1) break;
    }

    // In dãy con tang dài nh?t (theo th? t? tang d?n)
    printf("Day con tang dai nhat: ");
    for (int i = lisCount - 1; i >= 0; i--) {
        printf("%d ", lis[i]);
    }
    printf("\nDo dai: %d\n", maxLen);

    return 0;
}
