#include "stdio.h"
int main(){
	int n,m, i=1;
	printf("NHAP n: "); scanf("%d", &n);
	do {
		m= n%i;
		if(m==0) printf("UOC CUA n LA: %d\n", i);
		i++;
	} while (i<=n);	
}
