#include<stdio.h>
#include<string.h>

int isPalindrome(const char str[]){
	int left = 0;
	int right = strlen(str) - 1;
	while(left < right){
		if(str[left] != str[right]){
			return 0; //Khong phai la palindrome
		}
		left++;
		right--;
	}
	return 1; //La palindrome
}

int main(){
	char str[100];
	printf("Nhap chuoi: ");
	fgets(str,sizeof(str),stdin);
	
	if(str[strlen(str) - 1] == '\n'){
		str[strlen(str) - 1] = '\0';
	}
	if(isPalindrome(str)){
		printf("Chuoi la palindrome.\n");
	}else{
		printf("Chuoi khong phai la palindrome,\n");
	}
	return 0;
}
	
