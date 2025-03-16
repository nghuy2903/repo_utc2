#include "stdio.h"
int main(){
	int n;
	printf("Nhap n: "); scanf("%d", &n);
	int tam;
	printf("\nChu so dao nguoc cua %d la: ", n);
	while (n != 0 ){
		tam = n % 10;
		printf("%d", tam);
		n = n / 10;
	}
}
