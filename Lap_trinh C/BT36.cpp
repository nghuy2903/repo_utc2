#include "stdio.h"
void kiemtraSoDoiXung(int a[], int n){
	int j=n-1;
	for(int i=0;i<n/2; i++){
		if(a[i] != a[j]) {
			printf("Day so khong doi xung!");
			return;
		}
		j--;
	}
	printf("Day so doi xung!");
}
int kiemtraSoLe(int x){
	if(x%2!=0) return 1;
	 else return 0;
}
int demSoLeChiaHetCho3(int a[], int n){
	int dem=0;
	for(int i=0; i<n; i++){
		int x= kiemtraSoLe(a[i]);
		if(x == 1){
			int y = a[i] % 3 ;
			if( y == 0 ) dem++;
		}
	}
	return dem;
}
void xoaPhanTu(int a[], int &n, int ViTriXoa){
	for(int i = ViTriXoa + 1; i<n; i++){
		a[i-1] = a[i];
	}
	n--;
}
void xoaPhanTuLeChiaHetCho3(int a[], int &n){
	for(int i=0; i<n; i++){
		int x = kiemtraSoLe(a[i]);
		if(x == 1){
			int y = a[i] % 3;
			if(y == 0){
				xoaPhanTu(a, n, i);
				i--;
			}
		}
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
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(a[i] == a[j]) xoaPhanTu(a, n, j);
		}
	}
	xuatMang(a, n);
	// printf("\n");
	// kiemtraSoDoiXung(a, n);
	// int x = demSoLeChiaHetCho3(a, n);
	// printf("\nSo phan tu le chia het cho 3 la: %d", x);
	// printf("\n");
	// xoaPhanTuLeChiaHetCho3(a, n);
	// xuatMang(a, n);
	return 0;
}
