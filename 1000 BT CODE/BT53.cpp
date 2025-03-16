#include "stdio.h"
int main(){
	int n;
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<0);
	int thaythe = n, tam;
	tam = thaythe % 10;
	thaythe = thaythe / 10;
	int max = tam;
	while ( thaythe != 0){
		tam = thaythe % 10;
		if( tam > max) max = tam;
		thaythe = thaythe / 10;
	}
	thaythe = n;
	 int dem = 0;
	while (thaythe != 0){
		tam = thaythe % 10;
		if(tam == max) dem++;
		thaythe = thaythe / 10;
	}
	printf("\nSo luong chu so lon nhat cua %d la: %d", n, dem);
}


