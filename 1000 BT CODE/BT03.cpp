#include "stdio.h"
int main(){
	int n, i=1;
	float tong=0,a;
	printf("NHAP n: "); scanf("%d", &n);
	for(i; i<=n; i++){
	    a=float(1)/i;
		tong= tong+a;			
	}
	printf("TONG NGHICH DAO TU 1 DEN n LA: %.2f", tong);
	
	
}
