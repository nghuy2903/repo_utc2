#include "stdio.h"
#include "math.h"
int kiemtraSoNguyenTo(int n){
	int dem=0; 
	for(int i=1; i<=sqrt(n); i++){
		if(n%i==0) dem++;
	}
	if(dem==1) return 1;
	 else return 0;
}
int demCapSoNguyenTo(int a[], int n){
	int dem=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if (i!=j) {
				int x = a[i] + a[j];
				int y = kiemtraSoNguyenTo(x);
				if(y == 1) dem++;
			}
		}
	}
	return dem;
}
int main(){
	int n, a[10000];
	do{
	printf("Nhap n: "); scanf("%d", &n);
    } while (n<=0);
	for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	if(n<=5){
		for(int i=0; i<n; i++){
			printf("%3d", a[i]);
		}
	}
	 else {
	 	for(int i=0; i<n; i++){
	 		if(i%5==0) printf("\n");
	 		printf("%3d", a[i]);
			}
	 }
	int m = demCapSoNguyenTo(a, n);
	printf("\nSo cap so nguyen to trong mang la: %d", m);
}
