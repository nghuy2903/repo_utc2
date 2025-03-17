#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, *a;
	printf("Nhap n: "); scanf("%d", &n);
	
	a = (int*)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", a+i);
	}
	
	for(int i=0; i<n; i++){
		printf("%d ", *(a+i));
	}
	
	for(int i=2; i<n-1; i++){
		int j = i+1;
		*(a+i) = *(a+j);
	}
	
	--n;
	printf("\n");
	for(int i=0; i<n; i++){
		printf("%d  ", *(a+i));
	}
	
	free(a);
	return 0;
}

