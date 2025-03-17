#include "stdio.h"
#include "math.h"

void nhapHeSo(int n, int a[]){
	for(int i=0; i<=n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void inDaThuc(int n, int a[]){ 
    int j = n;
    nhapHeSo(n, a);
	for(int i =0; i<=n; i++){
		if(i == n) printf(" %d", a[i]);
		 else printf("%d*x^%d + ",a[i], j);
		j--;
	}
}
void tinhDaThucTaiX(int n, int a[], int x){ 
    int j = n, tong = 0;
	for(int i =0; i<=n; i++){
		tong += a[i]*pow(x, j);
		j--;
	}
	printf("  %d", tong);
}
void tinhGiaTriDaThucR(int n, int a[]){
	int j = n;
	nhapHeSo(1, a);
	printf("R(x) = ");
	for(int i=0; i<=n; i++){
		if(i == n) printf(" %d", a[i]);
		 else printf("%d*x^%d + ", a[i], j);
		j--;
	}
}
void tinhGiaTriDaThucQ(int n, int b[]){
	int j = n;
	nhapHeSo(2, b);
	printf("Q(x) = ");
	for(int i=0; i<=n; i++){
		if(i == n) printf(" %d", b[i]);
		 else printf("%d*x^%d + ", b[i], j);
		j--;
	}
}
void tongHaiDaThuc(int a[], int b[]){
	int j = 2;
	for(int j = 2; j>=0; j--){
		if ( j == 2) printf("%d*x^2 + ", b[0]);
		 else if( j == 1) printf("%d*x^1 + ", a[0] + b[1]);
		  else printf("%d", a[1] + b[2]);
	}
}
int main(){
	int n, x, a[10], b[10];
	printf("Nhap bac n: "); scanf("%d", &n);
	inDaThuc(n, a);
	printf("\n Nhap x: "); scanf("%d", &x);
	printf("\n Gia tri da thuc tai x la: ");
	tinhDaThucTaiX(n, a, x);
	printf("\n");
	tinhGiaTriDaThucR(1, a);
	printf("\n");
	tinhGiaTriDaThucQ(2, b);
	printf("\n");
	printf("K(x) = R(x) + Q(x) = ");
	tongHaiDaThuc(a, b);
}
