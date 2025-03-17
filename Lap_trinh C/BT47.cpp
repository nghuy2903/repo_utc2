#include "stdio.h"
#include "stdlib.h"

void nhapMang(int n, int *p){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("a[%d][%d] = ", i,j);
			scanf("%d", (p+i*n) + j);
		}
	}
}

void xuatMang(int n, int *p){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("  %d ", *((p+i*n) + j) );
		}
		printf("\n");
	}
}

void tongDuongCheoChinh(int n, int *p){
	int tong = 0;
	int i = 0, j = 0;
	while (i<n){
		tong += *((p + i*n) + j);
		i++, j++;
	} 
	printf("\nTong duong cheo chinh la: %d", tong);
}

void tichDuongCheoChinh(int n, int *p){
	int tich = 1, i=0, j = 0;
	while(i<n){
		tich *= *((p + i*n) + j);
		i++, j++;
	}
	printf("\nTich duong cheo chinh la: %d", tich);
}

void trungBinhCongDong(int n, int *p, int k){
	int tong = 0;
	float TBC = 0;
	for(int i = 0; i < n; i++){
		tong += *((p + (k-1)*n) +i);
	}
	TBC = float(tong) / n;
	printf("\nTrung binh cong cac phan tu tai dong thu %d la: %.2f", k, TBC);
}

int main(){
 	printf("Chuong trinh lam viec voi ma tran vuong\n");
 	int n, k;
 	do{
 		printf("Nhap bac cua ma tran: "); scanf("%d", &n);
	 } while (n<=0 && printf(" n > 0 !\n"));
 	int *p;
 	p = (int*)malloc(n*n*sizeof(int));
    nhapMang(n, p);
    printf("\nMa tran vua nhap la:\n");
    xuatMang(n, p);  
	  
    tongDuongCheoChinh(n, p);  
    
    tichDuongCheoChinh(n, p);
    do{
 		printf("\nNhap dong can tinh trung binh cong: "); scanf("%d", &k);
	} while (k <= 0 || k > n);
	
    trungBinhCongDong(n, p, k);
    
    free(p);
 }
