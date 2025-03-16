#include "stdio.h"
#include "math.h"
// TONG LUY THUA TANG DAN CHIA CHO TONG TANG DAN
int main(){
	int n, i=1, tong=0,m;
	float a, sum=0;
	printf("NHAP n: "); scanf("%d", &n);
	for(i; i<=n; i++){
		m = pow(n,i);
		tong= tong+ i;
		a= float (m)/tong;
		sum= sum+ a;	
	}
	printf("TONG LA: %.2f", sum);
	
}
