#include "stdio.h"
// TIM UOC LON NHAT CUA n
int main(){
	int n,m, max=1, i=1;
	printf("NHAP n: "); scanf("%d", &n);
    do{
    	m=n%i;
    	if (m==0 && i>max) max=i;
    	i++;
	} while (i<n);
	printf("UOC LON NHAT CUA n LA: %d", max);
}
