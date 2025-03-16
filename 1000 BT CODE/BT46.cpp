#include "stdio.h"
int kiemtraSoLe(int x){
	if (x % 2 != 0) return x;
	else return 0;
}
int main(){
	int n; 
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<0 && printf("LOI! n>=0\n"));
	int tong = 0, thaythe = n, tam;
	while (thaythe != 0){
		tam = thaythe % 10;
		int x= kiemtraSoLe(tam);
		tong+= x;
		thaythe = thaythe / 10;
	}
	printf("\nTong cac chu so le cua %d la %d", n, tong);
}
