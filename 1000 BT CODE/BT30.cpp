#include "stdio.h"
// KIEM TRA SO HOAN THIEN
int main(){
	int n,m, i=1, tong=0;
	printf("NHAP n: "); scanf("%d", &n);
	for(i; i<n; i++){
		m= n%i;
		if(m==0) tong= tong+i;
	}
	if(tong==n) printf("%d LA SO HOAN THIEN", n);
	  else printf("%d KHONG LA SO HOAN THIEN",n);
	
}
