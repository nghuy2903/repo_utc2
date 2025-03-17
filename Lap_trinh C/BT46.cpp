#include "stdio.h"
#include "math.h"

void nhapHeSo(int n, float a[]);
void xuatDaThuc(int n, float a[]);
void daoHam(int &n, float a[]);
void xoaPhanTu(float a[], int &n, int ViTriXoa);
void tinhGiaTriDaThuc(int n, float a[], float x);
int main(){
	int n = 3;
	float x = 5, a[10];
	nhapHeSo(n, a);
	printf("f(x) = ");
	xuatDaThuc(n, a);
	daoHam(n, a);
	printf("\n");
	printf("f'(x) = ");
	xuatDaThuc(n ,a);
	tinhGiaTriDaThuc(n, a, x);
}
void nhapHeSo(int n, float a[]){
	for(int i=0; i<=n; i++){
		printf("a[%d] = ", i);
		scanf("%f", &a[i]);
	}
}
void xuatDaThuc(int n, float a[]){	 
	if(a[0] == 1) printf("x^%d ", n);
	 else if(a[0] == -1) printf("-x^%d ", n); 
	  else if(a[0] != 0)printf("%.2f*x^%d ", a[0], n);
		for(int j = 1; j <= n; j++){ 
		  if(a[j] == 0) continue;
		   else if(a[j] > 0){
			 if(j == n) printf("+ %.2f", a[j]);
			 else if(a[j] == 1 && j != n-1) printf("+ x^%d ", n-j);
			  else if(a[j] == 1 && j == n-1) printf("+ x ");
			   else if(a[j] != 1 && j == n-1) printf("+ %.2f*x ", a[j]);
			    else printf("+ %.2f*x^%d ", a[j], n-j);
			}			   
			else {
             if(a[j] != 0 && j == n) printf(" %.2f", a[j]);
			  else if(a[j] == -1 && j != n-1 ) printf(" -x^%d ", n-j);
			   else if(a[j] == -1 && j == n-1) printf(" -x ");	
			    else if(a[j] != -1 && j == n-1) printf(" %.2f*x ", a[j]);		
			    else printf(" %.2f*x^%d ", a[j], n-j);
		}
	}
}
void xoaPhanTu(float a[], int &n, int ViTriXoa){
	for(int i= ViTriXoa +1; i<=n; i++){
		a[i-1] = a[i];
	}
	n--;
}
void daoHam(int &n, float a[]){
	for(int i=0; i<=n; i++){
		if(i == n) xoaPhanTu(a, n, i);
		 else{
		 	a[i] = a[i] * (n-i);
		 }
	}
}
void tinhGiaTriDaThuc(int n, float a[], float x){
	float tong = 0;
	for(int i=0; i<=n; i++){
		if(i == n) tong += a[i];
		 else tong += a[i] *pow(x, n-i); 
	}
	printf("\nf'(%.2f) = %.2f",x, tong);
}
