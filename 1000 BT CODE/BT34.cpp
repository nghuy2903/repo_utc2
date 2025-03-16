#include "stdio.h"
#include "math.h"
// TONG n CAN TU n DEN 1
int main(){
	int n, i=1;
	float sum=0;
	printf("NHAP n: "); scanf("%d", &n);
	for(i; i<=n;i++){
		sum= sqrt(i+sum);		
	}
    printf("TONG LA: %.2f", sum);	
}
