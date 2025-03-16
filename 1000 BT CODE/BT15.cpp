#include "stdio.h"
// TONG NGHICH DAO CUA TONG CAC SO TAWNG DAN
int main(){
	int n, i=1, tong=0;
	float a, sum= 0;
	printf("NHAP n: "); scanf("%d", &n);
	do{
		tong= tong+i;
		i++;
		a= float(1)/tong;
		sum = sum+a;
	} while (i<=n);	
	printf("TONG LA: %.2f", sum);
	
}
