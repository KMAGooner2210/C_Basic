#include<stdio.h>
int main(){
	int rows, cols;
	printf("Nhap kich thuoc ma tran(rows x cols): ");
	scanf("%d %d", &rows, &cols);
	
	
	int matrix[100][100];
	printf("Nhap ma tran %d x %d\n", rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	
	printf("Ma tran:\n");
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
