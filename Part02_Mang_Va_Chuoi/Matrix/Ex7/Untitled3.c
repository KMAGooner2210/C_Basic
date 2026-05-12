// **7.	Nhân ma trận** 
// ```
// o	Yêu cầu: Nhập hai ma trận, tính tích của chúng theo quy tắc toán học và in kết quả.
// o	Output mẫu: 
// Nhap ma tran A 2x3:
// matrixA[0][0] = 1
// matrixA[0][1] = 2
// matrixA[0][2] = 3
// matrixA[1][0] = 4
// matrixA[1][1] = 5
// matrixA[1][2] = 6
// Nhap ma tran B 3x2:
// matrixB[0][0] = 7
// matrixB[0][1] = 8
// matrixB[1][0] = 9
// matrixB[1][1] = 10
// matrixB[2][0] = 11
// matrixB[2][1] = 12
// Ma tran tich:
// 58 64
// 139 154
// ```
#include<stdio.h>

int main(){
    int rowsA, colsA, rowsB, colsB;
    int matrixA[100][100], matrixB[100][100], result[100][100];
    
    
    printf("Nhap kich thuoc ma tran A (rows x cols): ");
    scanf("%d %d", &rowsA, &colsA);
    
    
    printf("Nhap ma tran A %dx%d:\n", rowsA, colsA);
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsA; j++){
            printf("matrixA[%d][%d] = ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    
    printf("Nhap kich thuoc ma tran B (rows x cols): ");
    scanf("%d %d", &rowsB, &colsB);
    
    
    if(colsA != rowsB){
        printf("Khong the nhan hai ma tran nay!\n");
        return 1;
    }
    
    
    printf("Nhap ma tran B %dx%d:\n", rowsB, colsB);
    for(int i = 0; i < rowsB; i++){
        for(int j = 0; j < colsB; j++){
            printf("matrixB[%d][%d] = ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }
    
    
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsB; j++){
            result[i][j] = 0;
        }
    }
    
    
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsB; j++){
            for(int k = 0; k < colsA; k++){
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    
    printf("Ma tran tich:\n");
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsB; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
