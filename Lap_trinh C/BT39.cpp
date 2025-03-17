#include<stdio.h>
#include "math.h"

int main()
{
 int m, n;
 printf("Chuong trinh ve hinh chu nhat kich thuoc MxN rong bang ngoi sao.\n");
 do{
 	printf("Nhap chieu rong: ");
 	scanf("%d", &m);
 } while (m<=0 && printf("m>0!\n"));
 do{
 	printf("Nhap chieu cao: ");
 	scanf("%d", &n);
 } while (n<=0 && printf("n>0!\n"));
 for(int i=1; i<=n; i++){
 	for(int j=1; j<=m; j++){
	 if( i == 1 || j == 1 ) printf(" * ");	
 	    else if(i == n || j == m) printf(" * ");
 		 	else printf("   "); 
	 }
 	printf("\n");
 }
}
