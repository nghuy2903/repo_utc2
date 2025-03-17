#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct sinhVien{
	char ten[100];
	float diem;
}sinhvien;

typedef struct Node{
	sinhvien x;
	Node *next;
}node;

typedef struct List{
   node *head;
   node *tall;	
}list;

node *creatNode(sinhvien a){
	node *p = (node*)malloc(sizeof(node));
	p->x = a;
	p->next = NULL;
	return p;
}

void themDau(node *p, list *l){
	if(l->head == NULL){
		l->head = p;
		l->tall = p;	
	}
	else {
	   p->next = l->head;
	   l->head = p;
	}
}

void themCuoi(node *p, list *l){
	if(l->head == NULL) l->head = p;
	 else {
	 	l->tall->next = p;
	 	l->tall = p;
	 }
}

void themBatKy(list *l, node *p, int viTriThem){
	if(viTriThem == 1){
		p->next = l->head;
		l->head = p;
	} 
	 else if(viTriThem <= 0){
	 	printf("\nVi tri sai!");
	 	return;
	 }
	 else {
	  node *temp = l->head;
	  for(int i=1; i<viTriThem-1; i++){
		temp->next = temp;
	   }
      p->next = temp->next;
	  temp->next = p;
	}
}

void xoaDau(list *l){
	l->head = l->head->next;
}

void xoaCuoi(list *l){
	if(l->head == NULL){
		printf("\nDanh sach chua co phan tu nao den xoa!");
	}
	 else {
	 	node *temp = l->head;
	 	while(temp->next != l->tall){
	 		temp = temp->next;
		 }
		 l->tall=temp;
		 temp->next = NULL;
	 }
}

void xoaBatKy(list *l, int viTriXoa){
	if(l->head == NULL){
		printf("\nDanh sacnh khong co phan tu nao de xoa!");
	}
	 else {
	 	node *temp = l->head;
	 	for(int i=1; i<viTriXoa-1; i++){
	 		temp = temp->next;
		 }
		 if(temp->next == NULL){
		 	printf("\nVi tri khong hop le!");
		 	return;
		 }
		 else temp->next = temp->next->next;
	 }
}

void nhapSinhVien(sinhvien &x){
	printf("\nNhap ten sinh vien: ");
    fflush(stdin);
	fgets(x.ten, sizeof(x.ten), stdin);
	printf("\nNhap diem: "); scanf("%f", &x.diem);
}

void xuatSinhVien(sinhvien x){
	printf("\nSinh vien:%s\t-Diem: %.2f", x.ten, x.diem);
}

int main(){
	sinhvien x, y, z;
	node *a = (node*)malloc(sizeof(node));
	node *b = (node*)malloc(sizeof(node));
	node *c = (node*)malloc(sizeof(node));
    a = creatNode(x);
	b = creatNode(y);
	c = creatNode(x);
		
	list *l = (list*)malloc(sizeof(list));
	l->head = NULL;
    
    themDau(a, l);
	themCuoi(b, l);
    for(node *i = l->head; i!=NULL; i = i->next){
    	nhapSinhVien(i->x);
	}	
	nhapSinhVien(c->x);
    themBatKy(l, c, 1);
    xoaBatKy(l, 2);
    
    for(node *i = l->head; i!=NULL; i = i->next){
    	xuatSinhVien(i->x);
	}

	free(a);
	free(b);
	free(l);
	return 0;
}

