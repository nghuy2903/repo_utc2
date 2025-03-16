#include"stdio.h"
#include"math.h"
int TONG_MU_TANG_DAN(int x){
	int y,z, sum=0;
	for(int i=1; i<=x; i++ )
	{
		y= pow(-1, i);
		z= pow(x, 2*i);
		sum+= y*z;
	}
	return sum;
}
int main(){
	int n, i;
	printf("NHAP n: "); scanf("%d", &n);
	int a= TONG_MU_TANG_DAN(n);
	printf("TONG LA: %d", a);
	
}
