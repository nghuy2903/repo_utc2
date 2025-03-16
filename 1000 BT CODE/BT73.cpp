#include"stdio.h"
#include"math.h"
float TONG_LUY_THUA_CHAN_CHIA_DAY_THUA_CHAN(int x){
	int tich=1, j=0, m, p;
	float sum=0;
	for(int i=1 ; i<=x ; i++){
    	m= pow(-1, i+1);
    	p= pow(x, 2*i);
    	j++;
    	tich*=j;
    	j++;
    	tich*=j;
		sum+= float(m*p)/ tich;
	}
	return sum;	
}
int main(){
	int n;
	do{
	printf("NHAP n: "); scanf("%d",&n);
}   while (n<0 && printf("n>0\n"));
    float a= TONG_LUY_THUA_CHAN_CHIA_DAY_THUA_CHAN(n);
	printf("TONG LA: %.2f", a-1);
}
