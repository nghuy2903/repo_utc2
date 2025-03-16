#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void nhapMang(int n, int *p){
	for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", p+i);
	}
}

void xuatMang(int n, int *p){
	for(int i=0; i<n; i++){
		printf(" %d ", *(p+i));
	}
}

int kiemTraSoHoanThien(int n){
	int dem = 0;
	for(int i=1; i<n; i++){
		if(n % i == 0) dem += i;
	}
	if(dem == n) return 1;
	 else return 0;
}

int kiemTraSoNguyenTo(int n){
	int dem = 0;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0) dem ++;
	}
	if(dem == 1) return 1;
	 else return 0;
}

void timSoNguyenToCuoiCung(int n, int *p, int *q){
	int j = 0;
	for(int i=0; i<n; i++){
		int x = kiemTraSoNguyenTo(*(p+i));
		if(x == 1) {
			*(q+j) = *(p+i);
			j++;
		}
	}
    if(j != 0) printf("\n   %d", *(q+j-1));
     else printf("\n   -1");
}

int main(){
	int *arr1, *arr2, n = 5;
	arr1 = (int*)malloc(n*sizeof(int));
	arr2 = (int*)malloc(n*sizeof(int));
	nhapMang(n, arr1);
	
	xuatMang(n, arr1);
	
    timSoNguyenToCuoiCung(n, arr1, arr2);
    
	free(arr1);
	free(arr2);
	return 0;
}
