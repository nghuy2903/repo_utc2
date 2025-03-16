#include "stdio.h"
#include "math.h"
// TONG LUY THUA CHAN CHIA CHO DAY THUA CHAN
int main(){
	int n,m,p=0, i=1, tich=1;
	float a, sum=1;
	printf("NHAP n: "); scanf("%d", &n);
	while (i<n){	
	   m= pow(n,2*i);
	   p++;
	   tich = tich*p;
	   p++;	
	   tich= tich*p;
	   i++;
	   a = float(m)/ tich;
		sum+=a;
}
	printf("TONG LA: %.2f", sum);	
}
