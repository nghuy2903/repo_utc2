#include "stdio.h"
int sosanhHaiSo(int a, int b){
	if(a > b) return 1;
	 else return 0;
}
int main(){
	int n, a[1000]; 
	do {
		printf("Nhap n: "); scanf("%d", &n);
	} while (n< 0 );
	int thaythe = n , tam, i = 0, tong =0;
	while (thaythe != 0){
		tam = thaythe % 10;
		a[i] = tam;
		thaythe = thaythe / 10;
		i++;
		tong++;
	}
	int b = i, sum = 0;
	for(int i = b-1; i>0; i--){
		int j = i -1;
		int x = sosanhHaiSo(a[i], a[j]);
		if( x == 0) printf("Cac chu so cua %d khong giam dan tu trai sang phai!", n);
         else sum+=x;
	}
	if (tong - 1 == sum ) printf("Cac chu so cua %d giam dan tu trai sang phai!", n);
}
