#include "stdio.h"
#include "math.h"
int main(){
	int n;
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<0);
	float x = sqrt( n);
	for(int i = 1; i< x +1; i++){
		int y = pow (2, i);
		if(y == n) {
			printf("%d la so co dang 2^k!", n);
			return 0;
		}
	}
}

