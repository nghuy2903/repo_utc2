#include "stdio.h"
#include"math.h"
int main(){
	int n,i=1, sum=0,m,p;
	printf("NHAP n: "); scanf("%d", &n);
	for(i; i<=n; i++){
		m= pow(-1, i+1);
		p= pow(n, i);
		sum = sum+ m*p;
	}
	printf("MACLAURENT: %d ", sum);
}
