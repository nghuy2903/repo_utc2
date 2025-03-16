#include "stdio.h"
// TICH CAC SO LIEN TIEP
int main(){
	int n, i=1, tich=1;
	printf("NHAP n: "); scanf("%d", &n); 
	while (i<=n){
		tich = tich*i;
		i++;		
	}
	printf("TICH LA: %d", tich);
	
}
