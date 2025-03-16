#include"stdio.h"
// TONG NGHICH DAO PHAN SO LIEN TIEP
int main(){
	int n, i=1, m=2;
	float a, tong=0;
	printf("NHAP n: "); scanf("%d", &n);
	do{
		label: a= float(i)/m;
		i++;
		m++;
		tong= tong+a;
	} while(i<=n); 
	printf("TONG LA: %.2f", tong);
	
}
