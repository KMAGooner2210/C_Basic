#include<stdio.h>

int main(){
	int rows, cols;
	int matrix[100][100];
	int trans[100][100];
	printf("Nhap kich thuoc ma tran rows x cols: ");
	scanf("%d %d", &rows, &cols);
	
	printf("Nhap ma tran %dx%d:\n", rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			trans[j][i] = matrix[i][j];
		}
	}
	
	printf("Ma tran chuyen vi:\n");
	for(int i = 0; i < cols; i++){
		for(int j = 0; j < rows; j++){
			printf("%d ", trans[i][j]);
		}
		printf("\n");
		}
	return 0;
}

