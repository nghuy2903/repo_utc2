#include "stdio.h"
// TONG CAC UOC CUA n
int main(){
	int n,m, i=1, tong=0;
	printf("NHAP n: "); scanf("%d", &n);
	for (i; i<=n; i++){
		m= n%i;
		if(m==0) tong= tong+i;
		
	}
	printf("TONG LA: %d", tong);
}
