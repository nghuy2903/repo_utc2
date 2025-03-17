#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int* elements;
    int size;
} Vector;

// Ham tinh tich vo huong cua 2 vecto
int dotProduct(Vector vector1, Vector vector2) {
    int result = 0;
    for (int i = 0; i < vector1.size; i++) {
        result += vector1.elements[i] * vector2.elements[i];
    }
    return result;
}

// Ham tinh chuan cua vecto
float vectorNorm(Vector vector) {
    float norm = 0.0;
    for (int i = 0; i < vector.size; i++) {
        norm += vector.elements[i] * vector.elements[i];
    }
    return sqrt(norm);
}

// Ham kiem tra ma tran truc giao
int isOrthogonalMatrix(Vector* matrix, int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = i + 1; j < cols; j++) {
            int dot = dotProduct(matrix[i], matrix[j]);
            if (abs(dot) > 0) {
                return 0; // Khong truc giao
            }
        }
    }
    return 1; // Ma tran truc gia
}

// Ham kiem tra ma tra truc chuan
int isOrthonormalMatrix(Vector* matrix, int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        float norm = vectorNorm(matrix[i]);
        if (fabs(norm - 1.0) > 0) {
            return 0; // Khong truc chuan
        }
    }
    return 1; // Ma tran truc chuan
}

int main() {
    int rows, cols;

    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &rows);

    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &cols);

    Vector* matrix = (Vector*)malloc(cols * sizeof(Vector));
    for (int i = 0; i < cols; i++) {
        matrix[i].size = rows;
        matrix[i].elements = (int*)malloc(rows * sizeof(int));
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phan tu thu [%d][%d]: ", i, j);
            scanf("%d", &(matrix[j].elements[i]));
        }
    }

    int isOrthogonal = isOrthogonalMatrix(matrix, rows, cols);
    int isOrthonormal = isOrthonormalMatrix(matrix, rows, cols);

    if (isOrthogonal){
        printf("Ma tran la ma tran truc giao.\n");
    } else{
        printf("Ma tran khong la ma tran truc giao.\n");
	}
        
    if(isOrthonormal){
        printf("Ma tran la ma tran truc chuan.\n");
    } else {
        printf("Ma tran khong la ma tran truc chuan.\n");
	}
        
}
