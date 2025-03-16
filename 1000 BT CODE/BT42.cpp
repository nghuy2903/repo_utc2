#include "stdio.h"
// TIM SO LON NHAT TRONG DAY S
int main(){
	int n, i=0, sum=0;
	do{printf("NHAP n: "); scanf("%d", &n);
	} while(n<=0);
	 label: i++;
	 sum= sum+i;
		if (sum<n){
		   goto label;
		}	
	printf("SO LON NHAT LA: %d", i=i-1);
}
