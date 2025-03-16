#include "stdio.h"
int timSoNhoHon(int a, int b){
	if ( a< b) return a;
	 else return b;
}
int timUocChungLonNhat(int x, int y){
	int a = timSoNhoHon(x, y);
	int max =1, b;
	for(int i = 1; i<=a; i++){
		if(x%i==0 && y%i==0){
			if(i>max) max=i;
		}
	}
	return max;
}
int main(){
	int n, m, p;
	do{
		printf("Nhap n: "); scanf("%d", &n);
	} while (n<0);
	do{
		printf("Nhap m: "); scanf("%d", &m);
	} while (n<0);
	int x = timUocChungLonNhat(n,m);
	p = (n*m)/ x;
	printf("Boi chung nho nhat cua %d va %d la: %d", n,m,p);
	
}
