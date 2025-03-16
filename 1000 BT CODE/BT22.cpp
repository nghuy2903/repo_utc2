#include "stdio.h"
int main (){
	int n,m,i=1, tich=1;
	printf("NHAP n: "); scanf("%d", &n);
	while (i<=n){
		m= n%i;
		if( m==0){
		 tich=tich*i;}	
		i++; 			
	}	
	printf("TICH LA: %d", tich);
}
