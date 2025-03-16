#include "stdio.h"
#include "math.h"
int main(){
	int n, a[1000];
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<0);
	if (n < 10 ) {	
	printf("n la so doi xung!");
	return 0;
	}	
	int thaythe = n, tam, i=0 , hang = 0, tong = 0;
	while (thaythe != 0){
		tam = thaythe % 10;
	    a[i] = tam;
		thaythe = thaythe / 10;
		i++;
		hang++;
		tong++;
	}
	int x, b;
	for(i = 0; i< tong; i++){
	   b = pow(10, (hang-1));
	   x += a[i] * b;
	   hang--;
	}
	if( x == n ) printf("%d la so doi xung!", n);
	 else printf("%d khong la so doi xung!", n);
}
