#include "stdio.h"
void kiemtraSoHoanHao(int n){
	int dem = 0;
	for(int i=1; i<n; i++){
		if( n % i == 0 ) dem+=i;
	}
	if (dem == n) {
		printf("%d la so hoan hao!", n);
		return;
	}
	 else {
	 	printf("%d khong la so hoan hao!", n);
	 	return;
	 }
}
int main(){
	int n;
	do{
	printf("Nhap n: "); scanf("%d", &n);
    } while (n<0 && printf("n>=0!\n")); 
	kiemtraSoHoanHao(n);
	
}
