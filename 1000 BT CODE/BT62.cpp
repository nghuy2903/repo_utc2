#include "stdio.h"
int timSoNhoHon(int a, int b){
	if (a < b ) return a;
	 else return b;
}
int timSoLonHon(int a, int b){
	if (a > b ) return a;
	 else return b;
}
int main(){
	int n, m;
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<0);
	do{
		printf("\nNhap m: "); scanf("%d", &m);
	} while (n<0);
	if (n==m){
		printf("\nUoc chung lon nhat cua %d va %d la: %d", n,m,n);
		return 0;
	}
	int x = timSoNhoHon(n, m);
	int max = 1, y;
	for (int i = 1; i <= x; i++ ){
		if(n%i==0 && m%i==0)
		 y = timSoLonHon(max, i);
	}
	printf("\nUoc chung lon nhat cua %d va %d la: %d", n,m,y);
}
