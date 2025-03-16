#include"stdio.h"
#include"math.h"
int TONG_MU_LE(int x){
	int n,m, sum=0;
	if(x>=0){
	for(int i=0; i<=x; i++){
		n= pow(-1, i);
		m= pow(x, 2*i+1);
		sum+=n*m;
	}
	return sum;}
}
int main(){
	int n;
	do{
	printf("NHAP n: "); scanf("%d",&n);} while(n<0 && printf("n > 0\n"));
	int a= TONG_MU_LE(n);
	printf("TONG LA: %d", a);
}
