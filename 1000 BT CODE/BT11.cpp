#include "stdio.h"
int main(){
	int n, i=1, tong=0, tich=1;
	printf("NHAP n: "); scanf("%d", &n);
	for(i; i<=n; i++){
		tich= tich *i;
		tong= tong+tich;		
	}
	printf("TONG: %d", tong);	
}
