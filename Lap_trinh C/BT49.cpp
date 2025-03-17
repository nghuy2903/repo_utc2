#include "stdio.h"
#include "math.h"

struct soPhuc{
	float a, b;
};

void nhap(soPhuc &a){
	printf("Nhap a: "); scanf("%f", &a.a);
	printf("Nhap b: "); scanf("%f", &a.b);
}

void xuat(soPhuc a){
	if(a.a == 0) printf(" %.2f", a.b);
	 else if(a.b == 0) printf(" %.2f", a.a);
	  else if(a.b == 1) printf(" %.2f + i", a.a);
	   else printf(" %.2f + %.2fi", a.a, a.b);
}

void tong(soPhuc a, soPhuc b){
	struct soPhuc c;
	c.a = a.a + b.a;
	c.b = a.b + b.b;
	xuat(c);
}

void hieu(soPhuc a, soPhuc b){
	struct soPhuc c;
	c.a = a.a - b.a;
	c.b = a.b - b.b;
	xuat(c);
}

void tich(soPhuc a, soPhuc b){
	struct soPhuc c;
	c.a = a.a * b.a;
	c.b = a.b * b.b;
	xuat(c);
}

void thuong(soPhuc a, soPhuc b){
	struct soPhuc c;
	c.a = float(a.a) / b.a;
	c.b = float (a.b) / b.b;
	xuat(c);
}

float modunSoPhuc(soPhuc a){
     float x;
     x = sqrt(a.a * a.a + a.b * a.b);
     return x;
}

void soSanhHaiSoPhuc(soPhuc a, soPhuc b){
	float x = modunSoPhuc(a);
	float y = modunSoPhuc(b);
	if (x > y ) printf("\nSo phuc a > So phuc b");
	 else if(x < y) printf("\nSo phuc a < So phuc b");
	  else printf("\n So phuc a = So phuc b");
}

int main(){
	struct soPhuc a, b;
	nhap(a);
	printf("So phuc a co dang: "); xuat(a);
	printf("\n");
	nhap(b);
	printf("So phuc b co dang: "); xuat(b);
	printf("\n");
	
	printf("Tong hai so phuc: ");
	tong(a, b);
	
	printf("\nHieu hai so phuc: ");
	hieu(a, b);
	
	printf("\nTich hai so phuc: ");
	tich(a, b);
	
	printf("\nThuong hai so phuc: ");
	thuong(a, b);
	
	float x = modunSoPhuc(a);
	printf("\n Modun so phuc a = %.2f", x);
	soSanhHaiSoPhuc(a, b);
}
