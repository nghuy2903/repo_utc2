#include "stdio.h"
void Swap(int &a, int &b){
	int tam = a;
	a = b; 
	b = tam;
}
void sapxepMangGiamDan(int a[], int n){
	for(int i = 0; i<n-1; i++){
		int ViTriLonNhat = i;
		for(int j=ViTriLonNhat+1; j<n; j++){
			if (a[j] > a[i] ){
				ViTriLonNhat = j;
				Swap(a[ViTriLonNhat], a[i]);
			}
		}
	}
}

void xuatMang(int a[],int n){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
int main(){
	int a[1000],n;
	printf("Nhap so luong phan tu: "); scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	sapxepMangGiamDan(a, n);
	printf("\nPhan tu lon thu 2 cua mang la: %d", a[1]);
	
}
