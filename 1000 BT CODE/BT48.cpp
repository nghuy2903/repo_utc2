#include "stdio.h"
int kiemtraSoLe(int x){
	if(x % 2 != 0) return x;
	 else return 1;
}
int main(){
	int n; 
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<=0 );
	int tich = 1, thaythe = n, tam;
	while (thaythe != 0){
		tam = thaythe % 10;
		int x = kiemtraSoLe(tam);
		tich*=x;
		thaythe = thaythe / 10;
	}
	printf("\nTich cac chu so le cua %d la: %d", n, tich);
}
