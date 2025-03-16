#include "stdio.h"
// TONG NGHICH DAO CUA CAC SO LE
int main(){
	int n, i=0,b ;
	float tong=0, a;
	printf("NHAP n: "); scanf("%d", &n);
	for(i; i<=n; i++){
		b= 2*i + 1;
		a= float(1)/b;
		tong= tong+a;		
	}
	printf("TONG: %.2f", tong);
	
}
