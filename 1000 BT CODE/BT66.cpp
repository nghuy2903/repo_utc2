#include "stdio.h"
#include"math.h"
int main (){
	float a,b,c;
	printf("GIAI PT: aX^4 + bX^2 + c = 0");
	printf("\nNHAP a= "); scanf("%f", &a);
	printf("\nNHAP b= "); scanf("%f", &b);
	printf("\nNHAP c= "); scanf("%f", &c);
	float m,p,q, x1, x2, x3, x4;
	m= sqrt(b*b - 4*a*c);
	if(m<0) printf("PT VO NGHIEM");
	p = (-b-m)/ 2*a;
	q = (-b+m)/ 2*a;
	if(p>0){
	 x1= sqrt(p);
	 x2= -sqrt(p);}
	 else printf("KHONG TON TAI x1, x2"); 
	 
	 
	if(q>0){
	 x3= sqrt(q);
	 x4= -sqrt(q);	
	}
	printf("x1= %.2f\n", x1);
	printf("x2= %.2f\n", x2);
	printf("x3= %.2f\n", x3);
	printf("x4= %.2f\n", x4);
}

