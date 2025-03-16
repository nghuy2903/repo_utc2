#include "stdio.h"
#include"math.h"
float TONG_TU_1_DEN_X(int x){
	int sum=0,n;
	float tong=0;
	for(int i=1; i<=x; i++){
		sum+=i;
		n= pow(-1, i+1);
		tong+= n*float(1)/sum;
	}
	return tong;
}
int main(){
	int n;
	printf("NHAP n: "); scanf("%d", &n);
	float a= TONG_TU_1_DEN_X(n);
	printf("TONg LA: %.2f", a);
}
