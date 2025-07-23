#include<stdio.h>
int main(){
	int rows, cols;
	int matrix[100][100];
	printf("Nhap ma tran co kich thuoc rows x cols: ");
	scanf("%d %d", &rows, &cols);
	printf("Nhap ma tran %dx%d:\n", rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	
	int isDoiXung = 1; //1:true, 0:false
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(matrix[i][j] != matrix[j][i]){
				isDoiXung = 0;
				break;
			}
		}
		if(!isDoiXung) break;
	}
	if(isDoiXung) {
		printf("Ma tran doi xung.\n");
	}else{
		printf("Ma tran khong doi xung.\n");
	}
	return 0;
}
