#include "stdio.h"
#include "conio.h"
#include "math.h"

float timChan(int n){
	if(n % 2 == 0) return n;
	 else return 0;
}

int main(){
	int n, dem = 0, j=0;
	float a[1000], b[1000], x, y;
	printf("Nhap so luong phan tu mang 1 chieu: "); scanf("%d", &n);
    for(int i=0; i<n; i++){
    	printf("a[%d] = ", i);
    	scanf("%f", &a[i]);
	}
	for(int i=0; i<n; i++){
		x = timChan(a[i]);
		if(x != 0) {
			b[j] = a[i];
			dem ++;
            j++;
			
		}
	}
	for(j=0; j<dem; j++){
		printf("%2.3f", b[j]);
	}
	printf("\n%2.3f", b[dem-1]);
   	getch();
}

