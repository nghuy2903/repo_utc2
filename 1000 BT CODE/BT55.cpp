#include "stdio.h"
int main(){
	int n;
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<0);
	int dem=0, thaythe = n, tam;
	while (thaythe != 0){
		tam = thaythe % 10;
		thaythe = thaythe / 10;
	}
	int x;
	thaythe = n;
	while (thaythe != 0){
	   x = thaythe % 10;
	   if( tam == x) dem++;
	   thaythe = thaythe / 10;	
	}
	printf("\nSo luong chu so dau tien cua %d la: %d", n, dem);
}
