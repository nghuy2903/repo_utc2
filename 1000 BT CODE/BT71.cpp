#include"stdio.h"
#include"math.h"
float TONG_MU_CHIA_TONG(int x){
	int n,m,sum=0;
	float tong=0;
	for(int i=1; i<=x; i++){
		n= pow(-1,i);
		m= pow(x,i);
		sum+=i;
		tong+= n*float(m)/ sum;
	}
	return tong;
}
int main(){
	int n;
	printf("NHAP n: "); scanf("%d",&n);
	float a= TONG_MU_CHIA_TONG(n);
	printf("TONG LA: %.2f", a);
}
