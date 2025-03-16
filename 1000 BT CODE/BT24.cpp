#include "stdio.h"
// LIET KE UOC LE CUA n
int main (){
	int n,m,p, i=1;
	printf("NHAP n: "); scanf("%d", &n);
	for (i; i<=n; i++){
		m= n%i; 
		p= i%2;
		if (m==0 && p!=0) printf("UOC LE CUA n LA: %d\n", i);
	}	
}
