#include "stdio.h"
#include "math.h"

typedef struct phanSo{
	int tu, mau;
}phanSo;

void nhap(phanSo &p){
	printf("Nhap tu: "); scanf("%d", &p.tu);
	printf("\nNhap mau: "); scanf("%d", &p.mau);
}

void xuat(phanSo p){
	if(p.tu == p.mau) printf("\n  1");
	 else if(p.mau == 1) printf("\n  %d", p.tu);
	  else if(p.tu == 0) printf("\n   0");
	   else printf("\n  %d / %d", p.tu, p.mau);
}

int timUCLN(phanSo p){
	int max = 1;
	int x = p.tu > p.mau ? p.tu : p.mau;
	for(int i = 1; i<=x; i++ ){
		if(p.tu % i == 0 && p.mau % i == 0){
		    max = i;
		}
	}
	return max;
}

void rutGonPhanSo(phanSo &p){
	int x = timUCLN(p);
	p.tu = float(p.tu) / x;
	p.mau = float(p.mau) / x;
}

phanSo tong(phanSo p1, phanSo p2){
	phanSo t;
	t.tu=p1.tu*p2.mau+p1.mau*p2.tu;
	t.mau = p1.mau*p2.mau;
	rutGonPhanSo(t);
	return t;
}
int main(){
	struct phanSo p1, p2, t;
	nhap(p1);
	nhap(p2);
	rutGonPhanSo(p1);
	xuat(p1);
//	t=tong(p1,p2);
//	xuat(tong(p1,p2));
}

