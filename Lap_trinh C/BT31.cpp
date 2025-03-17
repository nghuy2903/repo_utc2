#include "stdio.h"
void inputMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void outputMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
float tinhTrungBinhCongDuong(int a[], int n){
	int demDuong=0; 
	int tongDuong =0;
	for(int i=0; i<n; i++){
		if(a[i] > 0){
			tongDuong += a[i];
			demDuong ++;
		}
	}
	if(demDuong == 0) return demDuong;
	 else{
	   float TBCD;
	    TBCD = float(tongDuong)/demDuong;
        return TBCD;}
}
	int demAm=0; 
	int tongAm = 0;
float tinhTrungBinhCongAm(int a[], int n){
	for(int i=0; i<n; i++){
		if(a[i] < 0){
			tongAm += a[i];
			demAm++;
		}
	}
	if (demAm == 0) return demAm;
	 else{
    	float TBCA;
	    TBCA = float(tongAm)/demAm;
        return TBCA;}
}
int main(){
	int a[10000], n;
	printf("Nhap so luong phan tu cua mang: "); scanf("%d", &n);
	inputMang(a, n);
	outputMang(a, n);
	printf("\n");
	float x = tinhTrungBinhCongDuong(a, n);
	float y = tinhTrungBinhCongAm(a, n);
	if( x == 0) printf("Mang khong co phan tu duong !\n"); 
	 else printf("Trung binh cong cac phan tu duong la: %.2f\n", x);
	if( y == 0) printf("Mang khong co phan tu am!\n");
	 else printf("Trung binh cong cac phan tu am la: %.2f", y) ;	
}
