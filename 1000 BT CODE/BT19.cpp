#include "stdio.h"
#include "math.h"
// TONG LUY THUA LE CHIA CHO DAY THUA LE
int main(){
   int n,m,p=1, i=1, tich=1;
   float a, sum = 1;
   printf("NHAP n: "); scanf("%d", &n);
   for (i; i<=n; i++){
   	    m= pow(n, 2*i+1);
   	    p++;
   	    tich= tich*p;
   	    p++;
   	    tich*=p;
   	    a= float(m)/tich;
   	 	sum+=a;
   }
   sum= sum+n;
   printf("TONG LA: %.2f", sum);
}
