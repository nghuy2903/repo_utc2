#include"stdio.h"
int kiemtraSoLe(int n){
	if (n % 2 != 0 ) return 1;
	 else return 0;
}
int main(){
	int n, m=0;
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<0);
	int thaythe = n, tam, dem = 0;
	while (thaythe != 0){
		tam = thaythe % 10;
		int x= kiemtraSoLe(tam);
		if (x == 1) dem ++; 
		thaythe = thaythe / 10; 
		m++;
	}
	if( dem == m)	printf("%d toan chu so le!", n);
	 else printf("%d chua chu so chan", n);
}
