#include "stdio.h"
int main(){
	int n, i=2;
	float a, sum= 0.5;
	do{
		printf("NHAP n(n>=1): "); scanf("%d", &n);
	} while (n<=0);
	for (i; i<=n; i++){ 
		sum = float(1)/(1+sum);	
	}
	printf("TONG LA: %.3f", sum);
	
}
