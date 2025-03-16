#include "stdio.h"
// DEM SO LUONG UOC CHAN CUA n
int main(){
	int n,m,p, i=1, sum=0;
	printf("NHAP n: "); scanf("%d", &n);
	for(i;i<=n;i++){
		m=n%i;
		p= i%2;
		if(m==0 && p==0) sum=sum+1;
	}
	printf("SO LUONG UOC CHAN CUA n LA: %d", sum);
}
