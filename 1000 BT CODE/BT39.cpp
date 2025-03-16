#include "stdio.h"
#include "math.h"
// TONG n CAN TANG DAN TU n DAY THUA DEN 1
int main(){
	int n, i=2,m=1, tich=1;
	float sum=0, a;
	do{printf("NHAP n(n>=1): "); scanf("%d", &n);
	}while (n<=0);
    for(m; m<=n; m++){
	   a= float(1)/ i;
	   tich*=m;
	   sum= pow(sum+tich, a);
	   i++;
}
    printf("TONG LA: %.2f", sum);
}
