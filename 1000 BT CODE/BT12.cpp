#include "stdio.h"
#include "math.h"
// TONG LUY THUS TANG DAN
int main(){
	int x,n,i=1, tong=0;
	printf("NHAP x: "); scanf("%d", &x);
	 label: n= pow(x,i);
	if(i<=x){	
	  tong= tong+n;
	  i++;
	  goto label;	
	}
	printf("TONG LA: %d", tong);
}
