#include "stdio.h"
//  TONG UOC CHAN CUA n
int main(){
	int n,m,p, i=1, tong=0;
	printf("NHAP n: "); scanf("%d", &n);
	while (i<=n){
		m= n%i;
		p= i%2;
		if(m==0 && p==0)
			tong= tong+i;
		i++;
	}
    printf("TONG CAC UOC CHAN CUA n LA: %d", tong);
}
