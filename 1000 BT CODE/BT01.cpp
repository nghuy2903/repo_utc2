#include "stdio.h"
int main(){
	int n, i=0,tong=0;
	printf("NHAP n: "); scanf("%d", &n);
	label: tong= tong+i;
	if(i<n){
		i++;
		goto label;		
	}
	printf("TONG CAC SO TU 1 DEN n LA: %d", tong);
	
}
