#include "stdio.h"
#include "math.h"
// TONG CAN GIAM DAN DEN 2
int main(){
	int n, i=2;
	float sum=0, m, a;
	do{
	printf("NHAP n(n>1): "); scanf ("%d", &n);
} while (n<=1);
	for(i; i<=n; i++){
		a = float(1)/ i;		
		sum = pow(sum+i, a);		
	}
	printf("TONG LA: %.2f", sum);
}
