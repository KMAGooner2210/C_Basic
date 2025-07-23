#include<stdio.h>
int main(){
	int rows, cols, sum = 0;
	int matrix[100][100];
	printf("Nhap kich thuoc ma tran rows x cols: ");
	scanf("%d %d", &rows, &cols);
	
	printf("Nhap ma tran %d x %d\n", rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
			sum += matrix[i][j];
		}
	}
	
	printf("Tong ma tran: %d\n",sum);
	return 0;
}
