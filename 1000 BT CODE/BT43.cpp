#include "stdio.h"
int main(){
	int n;
		printf("Nhap n: ");
		scanf("%d", &n);
	int sochuso=0, thaythe = n;
	
	while (thaythe!=0){
		sochuso++;
		thaythe = thaythe/10;
	}
    printf("So luong chu so cua %d la %d", n, sochuso);
}


