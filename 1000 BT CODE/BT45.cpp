#include "stdio.h"
int main(){
	int n;
	do{	
	printf("Nhap n: ");
	scanf("%d", &n);
	} while (n<0 && printf("LOI! n>=0\n"));
	int tich = 1, thaythe = n, tam;
	if (n == 0) tich = 0;
	while (thaythe != 0 ){
		tam = thaythe %10;
		tich*=tam;
		thaythe = thaythe / 10;
	}
	printf("Tich cac chu so trong %d la: %d", n, tich);
}
