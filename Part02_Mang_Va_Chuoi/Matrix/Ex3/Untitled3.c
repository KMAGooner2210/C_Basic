// **3.	Tính tổng hàng/cột** 
// ```
// o	Yêu cầu: Nhập ma trận, tính tổng từng hàng và từng cột.
// o	Output mẫu: 
// Nhap ma tran 2x3:
// matrix[0][0] = 1
// matrix[0][1] = 2
// matrix[0][2] = 3
// matrix[1][0] = 4
// matrix[1][1] = 5
// matrix[1][2] = 6
// Tong hang 0: 6
// Tong hang 1: 15
// Tong cot 0: 5
// Tong cot 1: 7
// Tong cot 2: 9
// ```
#include<stdio.h>
int main(){
	int matrix[100][100];
	int rows, cols;
	int rows_sum[100] = {0};
	int cols_sum[100] = {0};
	printf("Nhap kich thuoc ma tran rows x cols: ");
	scanf("%d %d", &rows, &cols);
	
	printf("Nhap ma tran %dx%d:\n", rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
			rows_sum[i] += matrix[i][j];
			cols_sum[j] += matrix[i][j];
		}
	}
	
	for(int i = 0; i < rows; i++){
		printf("Tong hang %d: %d\n", i, rows_sum[i]);
	}
	for(int j = 0; j < cols; j++){
		printf("Tong cot %d: %d\n", j, cols_sum[j]);
	}
	return 0;
}
