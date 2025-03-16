#include "stdio.h"
#include "math.h"
// TONG LUY THUA CHAN
int main(){
	int x, i=1, n, tong=0;
	printf("NHAP x: "), scanf("%d", &x);
	for(i; i<=x; i++){
		n= pow(x,2*i);
		tong= tong+n;
	}
	printf("TONG LA: %d", tong);
	
}
