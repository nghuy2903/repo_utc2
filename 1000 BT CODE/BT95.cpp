#include "stdio.h"
#include "math.h"
int main(){
	int a, b, c;
	printf("Nhap a: "); scanf("%d", &a);
	printf("nhap b: "); scanf("%d", &b);
	printf("Nhap c: "); scanf("%d", &c);
	if(a<0) a = abs(a);
	if(b<0) b = abs(b);
	if(c< 0) c = abs(c);
	printf("Gia tri tuyet doi cua cac so vua nhap la: %d %d %d", a, b, c);
}
