#include "stdio.h"
#include "math.h"
// TONG n CAN TU n DEN MOT( MU CAN TANG DAN)
int main(){
	int n, i=2, m= 1;
	float sum=0, a;
	do{ 
	printf("NAHP n: "); scanf("%d", &n);
	}while(n<=0);
	while(m<=n){
		a= float(1)/ i;		
		sum= pow(sum+m, a);
		i++;
		m++;
	}
	printf("TONG LA: %.2f", sum);
}
