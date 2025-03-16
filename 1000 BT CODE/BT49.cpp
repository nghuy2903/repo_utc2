#include "stdio.h"
#include "math.h"
int main(){
	int n;
	printf("Nhap n: "); scanf("%d", &n);	
	int thaythe = n, tam;
	if(n == 0) tam = 0;
	while ( thaythe != 0){
		tam = thaythe % 10;
		thaythe = thaythe / 10;
	}
	tam = abs(tam);	
	printf("\nChu so dau tien cua %d la: %d", n, tam);
}
	
