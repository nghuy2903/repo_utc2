#include "stdio.h"
int main(){
	int a, b, c;
	printf("Nhap a: "); scanf("%d", &a);
	printf("Nhap b: "); scanf("%d", &b);
	printf("Nhap c: "); scanf("%d", &c);
	int max;
	if(a>=b && a>=c ) max = a;
	 else if( b>=a && b>=c) max = b;
	  else max =c;
	printf("So lon nhat trong %d, %d, %d la: %d", a, b, c, max);
}
