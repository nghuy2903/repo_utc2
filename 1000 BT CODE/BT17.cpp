#include "stdio.h"
#include "math.h"
// TONG LUY THUA TANG DAN CHIA CHO DAY THUA TANG DAN
int main(){
	int n, i=1,m, tich= 1;
	float a, sum=0;
	printf("NHAP n: "); scanf("%d", &n);
	while (i<=n){
		m= pow(n,i);
	    tich=tich*i;
		a= float(m)/ tich;
		sum+=a;
		i++;
	}
	printf("TONG LA: %.2f", sum);
		
}
