#include"stdio.h"
int main(){
	int n;
	do{
	printf("Nhap n: ");
	scanf("%d", &n);
}   while (n<0 && printf("LOI! n>=0\n"));
	int tong = 0, thaythe = n, tam;
// TRONG VONG LAP, PHAI XUAT HIEN LAI BIEN DE KIEM TRA DIEU KIEN (WHILE)
	while (thaythe != 0){
		tam = thaythe % 10;
		tong += tam;
		thaythe = thaythe / 10;
	}
	printf("\nTong cac chu so cua %d la: %d ", n, tong);
}
