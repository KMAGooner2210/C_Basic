// **1.In ma trận**
// ``` 
// o	Yêu cầu: Nhập ma trận từ bàn phím và in ra màn hình.
// o	Output mẫu: 
// Nhap ma tran 2x3:
// matrix[0][0] = 1
// matrix[0][1] = 2
// matrix[0][2] = 3
// matrix[1][0] = 4
// matrix[1][1] = 5
// matrix[1][2] = 6
// Ma tran:
// 1 2 3
// 4 5 6
// ```

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
