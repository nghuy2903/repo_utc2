#include "stdio.h"
// KIEM TRA SO NGUYEN TO
int main (){
	int n,m, i=1, sum=0;
	printf("NHAP n: "); scanf("%d", &n);
	while (i<=n){
		m= n%i;
		if(m==0) sum= sum+1;
		i++;
	}
	if (sum==2) printf("%d LA SO NGUYEN TO", n);
	  else printf("%d KHONG LA SO NGUYEN TO", n);	
	
}
