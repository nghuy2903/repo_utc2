#include "stdio.h"

void nhapMang(int n, int *parr){
	for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", (parr +i));
	}
}

void xuatMang(int n, int *parr){
	for(int i=0; i<n; i++){
		printf("%d ", *(parr+i) );
	}
}
int main(){
	int n;
	printf("Nhap n: "); scanf("%d", &n);
	nhapMang(n, *parr);
	xuatMang(n, *parr);
}
