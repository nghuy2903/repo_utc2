#include "stdio.h"
#include "math.h"
//TONG LUY THUA LE
int main(){
	int x, n, i=0, tong=0;
	printf("NHAP x: "); scanf("%d", &x);
	while(i<=x){
		n= pow(x,(2*i+1));
		i++;
		tong=tong+n;
	}
	printf("TONG LA: %d", tong);
}
