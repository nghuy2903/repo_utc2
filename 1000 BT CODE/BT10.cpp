#include "stdio.h"
#include "math.h"
// TINH SO MU
int main(){
	int x, n, a;
	printf("NHAP x: "); scanf("%d", &x);
	printf("NHAP n: "); scanf("%d", &n);
	a= pow(x,n);
	printf("%d^%d = %d",x,n, a);
}
