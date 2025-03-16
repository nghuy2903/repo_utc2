#include "stdio.h"
// TONG CAC UOC NHO HON n 
int main(){
	int n,m, i=1, tong=0;
	printf("NHAP n: "); scanf("%d", &n);
	while(i<n){
	   m = n%i;
	   if (m==0) tong=tong+i;	
	   i++;
	}
	printf("TONG CAC UOC NHO HON n LA: %d", tong);
}
