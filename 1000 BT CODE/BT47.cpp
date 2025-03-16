#include "stdio.h"
int kiemtraSoChan(int x){
	if(x % 2 == 0 && x!=0) return x;
	else return 0;
}
int main(){
	int n;
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<=0);
	int tong = 0, thaythe = n, tam;
	while (thaythe != 0){
	   tam = thaythe % 10;
	   int x = kiemtraSoChan(tam);
	   tong += x;
	   thaythe = thaythe / 10;
	}
	printf("\nTong cac chu so chan cua %d la: %d", n, tong);
}
