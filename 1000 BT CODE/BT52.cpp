#include"stdio.h"
int main(){
	int n;
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<0);
	int thaythe = n, tam;
	tam = thaythe % 10;
	thaythe = thaythe / 10;
	int min = tam;
	while (thaythe != 0){
		tam = thaythe % 10;
		if (tam < min) min = tam;
		thaythe = thaythe / 10;
	}
	printf("\nChu so nho nhat cu %d la: %d", n, min);
}
