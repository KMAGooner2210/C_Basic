// **5.	Hoán đổi hàng/cột** 
// ```
// o	Yêu cầu: Nhập ma trận và hai chỉ số hàng hoặc cột, hoán đổi chúng.
// o	Output mẫu: 
// Nhap ma tran 2x3:
// matrix[0][0] = 1
// matrix[0][1] = 2
// matrix[0][2] = 3
// matrix[1][0] = 4
// matrix[1][1] = 5
// matrix[1][2] = 6
// Nhap hai hang can hoan doi: 0 1
// Ma tran sau khi hoan doi:
// 4 5 6
// 1 2 3
// ```
#include<stdio.h>
int main(){
	int rows, cols;
	int matrix[100][100];
	printf("Nhap kich thuoc rows x cols: ");
	scanf("%d %d", &rows, &cols);
	printf("Nhap ma tran %dx%d:\n",rows,cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	int rows1, rows2;
	printf("Nhap hai hang can hoan doi: ");
	scanf("%d %d", &rows1, &rows2);
	
	if(rows1 < 0 || rows1 >= rows || rows2 < 0 || rows2 >= rows){
		printf("Chi so hang khong hop le!\n");
		return 1;
	}
	
	for(int j = 0; j < cols; j++){
		int temp = matrix[rows1][j];
		matrix[rows1][j] = matrix[rows2][j];
		matrix[rows2][j] = temp;
	}
	
	printf("Ma tran sau khi hoan doi:\n");
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
		
	}
	return 0;
}
