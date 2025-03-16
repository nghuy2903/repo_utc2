#include "stdio.h"
// LIET KE CAC UOC CUA N
int main(){
	int i=1, n, m;
	printf("NHAP n: "); scanf("%d", &n);
    do {
    	m=n%i;
    	if (m==0) printf("UOC CUA n LA: %d\n", i);
    	i++;
	} while (i<=n);
}
