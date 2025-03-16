#include "stdio.h"
#include "math.h"
// TONG n CAN TU n MU 1 DEN n MU n
int main(){
	int n, i=1,m;
	float sum=0;
	do{printf("NHAP n(n>=1): "); scanf("%d", &n);
	} while(n<=0);
	for (i; i<=n;i++ ){
		m= pow(n,i);
		sum= sqrt(sum+m);		
	}
	printf("TONG LA: %.2f", sum);
}
