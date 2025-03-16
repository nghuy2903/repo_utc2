#include "stdio.h"
#include "math.h"
// TONG n CAN TU 1 DEN n
int main(){
	int n, i=0;
	float sum=0;
	printf("NHAP n: "); scanf("%d", &n);	
    for (n; n>0; n--){
	    	sum= sqrt(n+sum);
		}		
	printf("TONG LA: %.2f", sum);
}
