// **4.	Tìm số lớn nhất trong ma trận** 
// ```
// o	Yêu cầu: Nhập ma trận, tìm giá trị lớn nhất trong ma trận.
// o	Output mẫu: 
// Nhap ma tran 2x3:
// matrix[0][0] = 1
// matrix[0][1] = 2
// matrix[0][2] = 3
// matrix[1][0] = 4
// matrix[1][1] = 5
// matrix[1][2] = 6
// So lon nhat: 6
// ```
#include<stdio.h>
int main(){
	int rows, cols;
	int matrix[100][100];
	printf("Nhap kich thuoc ma tran rows x cols: ");
	scanf("%d %d", &rows, &cols);
	printf("Nhap ma tran %dx%d:\n", rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	int maxVal = matrix[0][0];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(matrix[i][j] > maxVal){
				maxVal = matrix[i][j];
			}
		}
	}
	printf("So lon nhat: %d\n", maxVal);
	return 0;
}
