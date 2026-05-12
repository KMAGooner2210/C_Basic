// **8.Đếm ký tự**
// ```
// o	Yêu cầu: Nhập chuỗi và ký tự, đếm số lần xuất hiện của ký tự đó.
// o	Output mẫu: 
// Nhap chuoi: banana
// Nhap ky tu: a
// So lan xuat hien: 3

#include<stdio.h>
#include<string.h>

int countChar(const char str[], char ch){
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == ch){
			count++;
		}
	}
	return count++;
}

int main(){
	char str[100];
	char ch;
	
	printf("Nhap chuoi: ");
	fgets(str,sizeof(str),stdin);
	
	if(str[strlen(str) - 1] == '\n'){
		str[strlen(str) - 1] = '\0';
	}
	
	printf("Nhap ky tu: ");
	scanf(" %c",&ch);
	
	int result = countChar(str, ch);
	printf("So lan xuat hien: %d", result);
	return 0;
}
