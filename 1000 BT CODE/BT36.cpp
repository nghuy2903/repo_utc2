#include "stdio.h"
#include "math.h"
// TONG n CAN TU n! DEN 1!
int main(){
	int n, i=1, tich=1;
	float sum=0;
	printf("NHAP n: "); scanf("%d", &n);
	while (i<=n){
		tich*=i;
		sum= sqrt(tich+sum);
		i++;
	}
	printf("TONG LA: %.2f", sum);
}
