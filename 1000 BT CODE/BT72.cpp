#include"stdio.h"
#include"math.h"
float TONG_MU_CHIA_DAY_THUA(int x){
	int n,m, tich=1;
	float tong;
	for(int i=1; i<=x; i++){
		n= pow(-1, i);
		m= pow(x, i);
		tich*=i;
		tong+= float(n*m)/ tich;
	}
	return tong;
}
int main(){
	int n;
	do{
	printf("NHAP n: "); scanf("%d", &n);
	} while (n<=0 && printf("n>0\n"));
	float a= TONG_MU_CHIA_DAY_THUA(n);
	printf("TONG LA: %.2f",a);	
}
