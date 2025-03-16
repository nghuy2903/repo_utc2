#include "stdio.h"
// TONG NGHICH DAO CUA CAC SO CHAN 
int main(){
	int n, i=1;
	float tong=0, a;
	printf("NHAP n: "); scanf("%d", &n);
	do{
		a=float(1)/(2*i);
		tong= tong+a;
		i++;		
	} while(i<=n);
	printf("TONG: %.2f", tong);
	
	
	
	
	
}
