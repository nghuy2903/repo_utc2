#include "stdio.h"
// TONG UOC LE CUA n 
int main(){
	int n,m,p, i=1, tong=0;
	printf("NHAP n: "); scanf("%d", &n);
	do {
		m= n%i;
		p=i%2;
		if (m==0 && p!=0) tong+=i;
		i++;
	} while(i<=n);
	printf("TONG: %d", tong);	
}
