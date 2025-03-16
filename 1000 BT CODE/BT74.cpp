#include"stdio.h"
#include"math.h"
float TONG_LUY_THUA_LE_CHIA_DAY_THUA_LE(int x){
	int n,m, j=1, tich=1;
	float sum=0;
	for (int i=1; i<=x; i++){
		n= pow(-1, i+1);
		m= pow(x,(2*i)+1);
		j++;
		tich*=j;
		j++;
		tich*=j;
		sum+= float(n*m)/ tich;
	}
	return sum;
}
int main(){
	int n; 
	do{
	printf("NHAP n: "); scanf("%d", &n);} while(n<0&& printf("n>=0\n"));
	float a= TONG_LUY_THUA_LE_CHIA_DAY_THUA_LE(n);
//	float tong;
//	tong= a ;
	printf("TONG LA: %.2f",a-n+1 );
}
