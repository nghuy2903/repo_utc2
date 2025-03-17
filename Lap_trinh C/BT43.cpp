#include "stdio.h"
#include "math.h"

void nhapHeSo(int n, int a[]){
	for(int i=n; i >= 0; i--){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void inDaThuc(int n, int a[]){ 
	for(int i = n; i>=0; i--){
		if(i == 0) printf(" %d", a[i]);
		 else printf("%d*x^%d + ",a[i], i);
	}
}
void tinhGiaTri(int n, int a[], int x){
	int tong = 0, j = n;
	for(int i=n; i>=0; i--){
		if( i == 0 ) tong += a[i];
		 else tong += a[i] * pow(x, i);
	}
	printf("\nGia tri da thuc tai x la: %d", tong);
}
void tongHaiDaThuc(int n, int a[], int m, int b[]){
	if(n < m){
	 for(int i=0; i<m; i++){
		b[i] = b[i] + a[i];
	 }
    }
     else if (n > m){
     	for(int i=0; i<n; i++){
		a[i] = b[i] + a[i];
	   }
	  }
	  else {
	  	for(int i=0; i<=n; i++){
		a[i] = b[i] + a[i];
	    }
       }
}
int main(){
	int p, n, m, x=5, a[10], b[10];
//	printf("Nhap bac p: "); scanf("%d", &p);
//	nhapHeSo(p, a);
//	printf("R(x) = ");
//	inDaThuc(p, a);
//	tinhGiaTri(p, a, x);
	printf("\nNhap bac A(x): "); scanf("%d", &n);
	nhapHeSo(n, a);
	printf("\nNhap bac B(x): "); scanf("%d", &m);
	nhapHeSo(m, b);
	printf("\nC(x) = A(x) + B(x) = ");
	tongHaiDaThuc(n, a, m, b);
	if( n < m) inDaThuc(m, b);
	 else inDaThuc(n, a);
}
