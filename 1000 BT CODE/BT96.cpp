#include"stdio.h"
int main(){
	printf("f(x) = 2x^2 + 5x + 9 khi x>=5\n");
	printf("f(x) = -2x^2 + 4x - 9 khi x<5\n");
	int x,y;
	printf("Nhap x: "); scanf("%d", &x);
	if (x >= 5) y = 2*x*x + 5*x + 9;
	 else y = -2*x*x + 4*x - 9;
	printf("Gia tri cua f(x) = %d", y); 
} 
