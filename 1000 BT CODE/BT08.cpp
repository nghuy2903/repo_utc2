#include "stdio.h"
int main(){
	int n, i=1, m=2;
	float a, tong=0;
	printf("NHAP n: "); scanf("%d", &n);
	for (i; i<=(2*n+1); i=i+2){
		a= float(i)/m;		
		m=m+2;
		tong= tong+a;
	}
	printf("TONG LA: %.2f", tong);
	
	
}
