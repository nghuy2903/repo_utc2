// chuong trinh sai
#include "stdio.h"
// KIEM TRA SO CHINH PHUONG
int main(){
	int n,m, i=1;
	printf("NHAP n: "); scanf("%d", &n); 
    if(n%2==0 && n%4==0) printf("%d LA SO CHINH PHUONG", n);
      else if(n%3==0 && n%9==0) printf("%d LA SO CHINH PHUONG", n);
        else if( n%5==0 && n%25==0) printf("%d LA SO CHINH PHUONG", n);
          else if(n%8==0 && n%16==0) printf(" %d LA SO CHINH PHUONG", n);
            else printf("%d KHONG LA SO CHINH PHUONG", n);
}
