#include "stdio.h"
#include "math.h"
// TONG n CAN BAC 2 CUA 2
int main(){
	int n, i=2;
	printf("NHAP n: "); scanf("%d", &n);
	float m=sqrt(2);
    for (i; i<=n;i++){
    	m=sqrt(2+m) ; 	
	}
	printf("TONG: %.2f", m);
}

