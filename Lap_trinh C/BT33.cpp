#include "stdio.h"
void xoaPhanTu(int a[], int &n, int ViTriXoa){
	for(int i= ViTriXoa + 1; i<n; i++){
		a[i-1] = a[i];
	}
	n--;
}
// KHI GOI HAM TRONG CAU LENH IF PHAI CO DAU "{}"
void xoaPhanTuTrung(int a[], int &n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if (a[i] == a[j]) {
			xoaPhanTu(a, n, j);
			j--;}
		}
	}
}
void timSoLanXuatHien(int a[], int &n, int x){
	int dem=0;
	for(int i=0; i<n; i++){
		if(a[i] == x) dem++;
	}
	if(dem == 0){
	 printf("%d khong xuat hien trong mang!", x);
	 n++;
	 a[n-1] = x;
	 printf("\n");
     for(int i=0; i<n; i++){
     	printf("%d ", a[i]);
	 }
	}
	 else printf("So lan %d xuat hien trong mang la: %d", x, dem);
}
void chenPhanTu(int a[], int &n, int ViTriChen, int GiaTriChen){
	n++;
	for(int i= n-1; i>=ViTriChen; i--){
		a[i] = a[i-1];
	}
	a[ViTriChen-1] = GiaTriChen;
}
void xuatMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
int main(){
	int n,x, y, a[10000];
	printf("Nhap so luong phan tu cua mang: "); scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	xuatMang(a, n);
	printf("\n");
//	printf("Mang sau khi xoa phan tu trung la: "); 
//	xoaPhanTuTrung(a, n);
//	xuatMang(a, n);
	printf("\nNhap x: "); scanf("%d", &x);
//	timSoLanXuatHien(a, n, x);
    do{
    printf("Nhap vi tri chen: "); scanf("%d", &y);
    } while ( y > n+1 && printf("Vi tri chen <= so luong phan tu!\n"));
    chenPhanTu(a, n, y, x);
    xuatMang(a, n);	
}
