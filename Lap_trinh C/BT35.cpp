#include "stdio.h"
int demCapSoChiaHet(int a[], int n){
	int dem=0;
	for(int i=0; i<n-1; i++){
		int j = i+1;
		if(a[j] % a[i] == 0) dem++;
	}
	return dem;
}
void themPhanTu(int a[], int &n, int ViTriChen, int GiaTriChen){
	n++;
	for(int i=n-1; i>=ViTriChen; i--){
		a[i] = a[i-1];
	}
	a[ViTriChen - 1] = GiaTriChen;
}
int main(){
	int n, y, z, a[100];
	printf("Nhap so luong phan tu cua mang: "); scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	int x = demCapSoChiaHet(a, n);
	printf("\nSo luong cap so chia het la: %d", x);
	printf("\nNhap gia tri chen: "); scanf("%d", &y);
	printf("Nhap vi tri chen: "); scanf("%d", &z);
	themPhanTu(a, n, z, y);
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
