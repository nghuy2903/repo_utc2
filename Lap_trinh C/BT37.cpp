#include "stdio.h"
void Swap(int &a, int &b){
	int tam = a;
	a = b;
	b = tam;
}
void sapxepMangGiamDan(int a[], int n){
	for(int i=0; i<n-1; i++){
		int ViTriLonNhat = i;
		for(int j = ViTriLonNhat+1; j<n; j++){
			if(a[ViTriLonNhat] < a[j]){
			ViTriLonNhat = j;
			}
		}
        Swap(a[ViTriLonNhat], a[i]);
	}
}
void xuatMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
int main(){
	int n, a[100];
	printf("Nhap n: "); scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	xuatMang(a, n);
	sapxepMangGiamDan(a, n);
	printf("\n");
	xuatMang(a, n);
}
