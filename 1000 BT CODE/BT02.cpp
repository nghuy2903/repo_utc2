#include "stdio.h"
int main(){
	int n, tong=0, i=1,a;
	printf("NHAP n: "); scanf("%d", &n);
	while (i<=n){
		a=i*i;
		tong = tong+a;
		i++;
	}
    printf("TONG LUY THUA CAC SO TU 1 DEN n LA: %d", tong);	
	
	
}
