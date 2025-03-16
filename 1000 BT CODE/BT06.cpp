#include "stdio.h"
int main(){
//TONG CAC SO NGHICH DAO LIEN TIEP
	int n, i=1, m=2,p;
	float tong=0, a;
	printf("NHAP n: "); scanf("%d", &n);
	while (i<=n){
		p= m*i;
		m++;
		i++;
		a= float(1)/ p;
		tong = tong+a;				
	}
	printf("TONG LA: %.2f", tong);
	
	
}
