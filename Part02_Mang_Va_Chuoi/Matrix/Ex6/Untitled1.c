// **6.	Ma trận chuyển vị** 
// ```
// o	Yêu cầu: Nhập ma trận, tìm ma trận chuyển vị (hoán đổi hàng thành cột).
// o	Output mẫu: 
// Nhap ma tran 2x3:
// matrix[0][0] = 1
// matrix[0][1] = 2
// matrix[0][2] = 3
// matrix[1][0] = 4
// matrix[1][1] = 5
// matrix[1][2] = 6
// Ma tran chuyen vi:
// 1 4
// 2 5
// 3 6
// ```

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

