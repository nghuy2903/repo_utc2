#include "stdio.h"
int main(){
	for(int i = 1; i<100; i++){
		if ( i != 5 && i != 7 && i!= 93) printf("%d, ", i);
		i++;
	}
}
