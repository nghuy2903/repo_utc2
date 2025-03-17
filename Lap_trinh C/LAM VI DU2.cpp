#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Node{
    float heSo, luyThua;
	struct Node* next;
}Node;

typedef struct{
	Node *head;
	Node *tall;
}list;

//Tao node moi
Node* createNode(float heSo, float luyThua) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
    	printf("Khong the cap phat bo nho!");
    	return NULL;
	}
    newNode->heSo = heSo;
    newNode->luyThua = luyThua;
    newNode->next = NULL;
    return newNode;
}

//Them dau danh sach
void themDau(Node *p, list *l){
	if(l->head == NULL){
		l->head = p;
		l->tall = p;	
	}
	else {
	   p->next = l->head;
	   l->head = p;
	}
}

void themCuoi(Node *p, list *l){
	if(l->head == NULL) l->head = p;
	 else {
	 	l->tall->next = p;
	 	l->tall = p;
	 }
}


void nhapHeSo(int n, float a[]){
	for(int i=0; i<=n; i++){
		printf("a[%d] = ", i);
		scanf("%f", &a[i]);
	}
}

void xuatDaThuc(int n, float a[]){	 
	if(a[0] == 1) printf("x^%d ", n);
	 else if(a[0] == -1) printf("-x^%d ", n); 
	  else if(a[0] != 0)printf("%.2f*x^%d ", a[0], n);
		for(int j = 1; j <= n; j++){ 
		  if(a[j] == 0) continue;
		   else if(a[j] > 0){
			 if(j == n) printf("+ %.2f", a[j]);
			 else if(a[j] == 1 && j != n-1) printf("+ x^%d ", n-j);
			  else if(a[j] == 1 && j == n-1) printf("+ x ");
			   else if(a[j] != 1 && j == n-1) printf("+ %.2f*x ", a[j]);
			    else printf("+ %.2f*x^%d ", a[j], n-j);
			}			   
			else {
             if(a[j] != 0 && j == n) printf(" %.2f", a[j]);
			  else if(a[j] == -1 && j != n-1 ) printf(" -x^%d ", n-j);
			   else if(a[j] == -1 && j == n-1) printf(" -x ");	
			    else if(a[j] != -1 && j == n-1) printf(" %.2f*x ", a[j]);		
			    else printf(" %.2f*x^%d ", a[j], n-j);
		}
	}
}

void xoaPhanTu(float a[], int &n, int ViTriXoa){
	for(int i= ViTriXoa +1; i<=n; i++){
		a[i-1] = a[i];
	}
	n--;
}

int timMax(int a, int b) {
   return a>b?a:b;
}


int main() {
    
    int x, n, m;
	float a[10], b[10];
	 
    printf("Nhap bac cua da thuc: "); scanf("%d", &n);
    nhapHeSo(n,a);
    printf("f(x) = ");
    xuatDaThuc(n,a); 
      
    list *l = (list*)malloc(sizeof(list));
	l->head = NULL;
	
    int temp = n;
    for(int i=0; i<=n; i++){
    	Node *newNode = createNode(a[i], temp--);
		if(i==0) themDau(newNode, l);
		 else themCuoi(newNode, l); 
    }

   printf("\nNhap bac cua da thuc: "); scanf("%d", &m);
   nhapHeSo(m,b);
   printf("g(x) = ");
   xuatDaThuc(m, b); 
   int max = timMax(n, m); 
   
   list *tong = (list*)malloc(sizeof(list));
   tong->head = NULL;
   
   if(n < m){
   	 int soSanh = sizeof(b)/sizeof(a);
   	 for(int i=0; i < soSanh; i++){
   	 	   a[++n] = 0;
		}
   } 
     else if(n > m){
     	int soSanh = sizeof(a)/sizeof(b);
   	    for(int i=0; i < soSanh; i++){
   	 	    b[++m] = 0;
		}
	 }
	 
	 int j = max;
    for(int i = 0; i<=j; i++){
   	Node *them = createNode(a[i] + b[i], max--);
   	if(i == 0) themDau(them, tong);
   	 else themCuoi(them, tong);
   }
   
//   printf("\n%.2f  %.2f", tong->tall->heSo, tong->tall->luyThua);

   printf("\nf(x) + g(x) = ");
   for(Node *t = tong->head; t != NULL; t= t->next){
   	 if(t->luyThua == 0) printf(" %.2f", t->heSo);
   	  else if(t->luyThua == 1) printf("%.2fx + ", t->heSo);
		else printf("%.2fx^%.0f + ", t->heSo, t->luyThua);
		
   }
    
    free(tong);
//    free(p);
    free(l);
//    free(them);
    
    return 0;
}
