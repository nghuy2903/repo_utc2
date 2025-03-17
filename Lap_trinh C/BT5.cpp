#include "stdio.h"

typedef struct phanSo{
	int tu, mau;
}p_s;

int timMax(int a, int b){
	return a<b ? a : b;
}

int timUCLN(int a, int b){
	int x = timMax(a, b), max = 1;
	for(int i=1; i<=x; i++){
		if (a%i == 0 && b%i == 0 ) max = i;
	}
	return max;
}

p_s rutGon(p_s *a){
    p_s b;
	int x = timUCLN(a->tu, a->mau);
	b.tu = int(a->tu) / x;
	b.mau = int(a->mau) / x;
	return b;
}

p_s tong(p_s a, p_s b){
	p_s t;
	t.tu = a.tu * b.mau + a.mau*b.tu;
	t.mau = a.mau*b.mau;
	return t;
	
}
void xuat(p_s a){
	printf("\n%d/%d", a.tu, a.mau);
}

int main(){
	p_s a, b;
   printf("Nhap tu so: ");
   scanf("%d", &a.tu);
   printf("\nNhap mau so: ");
   scanf("%d", &a.mau);
   xuat(rutGon(&a));
   b.tu = 4;
   b.mau = 5;
   xuat(tong(a, b));
}
