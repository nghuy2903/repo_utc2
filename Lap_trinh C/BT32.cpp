#include "stdio.h"
void gopXenKe(int a[], int n, int b[], int m, int c[], int p){
	int iA = 0, iB = 0, iC = 0;
	while (iA<n && iB <m){
		c[iC] = a[iA];
		iA++;
		iC ++ ;
		c[iC] = b[iB];
		iC++;
		iB++;
	}
	if(n<m){
		for(int i = n; i<m; i++){
			c[iC] = b[i];
			iC++;
		}
	}
    if(n>m){
    	for(int i = m; i<n; i++){
    		c[iC] = a[i];
    		iC++;
		}
	}
}
void xuatMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("  %d  ", a[i]);
	}
}
int main(){
	int a[10000], b[10000], c[10000], n, m;
	printf("Nhap so luong phan tu cua a[] : "); scanf("%d", &n);
	printf("Nhap so luong phan tu cua b[] : "); scanf("%d", &m);
    for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}  
    xuatMang(a, n);
    printf("\n");
    for(int i=0; i<m; i++){
		printf("b[%d] = ", i);
		scanf("%d", &b[i]);
	}
	xuatMang(b, m);
	printf("\n");
	int p = n+m;
	gopXenKe(a, n, b, m, c, p);
	xuatMang(c, p);
}

