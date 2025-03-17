#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
	int data;
	Node *next;
} node ; 

typedef struct List{
	node *head;
	
}list;

node* createNode(int n){
	node  *p = (node*)malloc(sizeof(node));
	p->data = n;
	p->next = NULL;
	return p;
}

void them(list *l, node*p){
	if(l->head == NULL){
		l->head = p;
	}
	 else{
	 	p->next = l->head;
	 	l->head = p;
	 }
}
int main(){
	node *p = (node*)malloc(sizeof(node));
//	p->data = 5;
//	p->next = NULL;
    p = createNode(5);
//	list l;
//	l.head = p;
    
	node *q = (node*)malloc(sizeof(node));
//	q->data = 10;
//	q->next = NULL;
    q = createNode(10);
//	l.head->next = q;
    list* l = (list*)malloc(sizeof(list));
    them(l, p);
    them(l, q);
	for(node *i = l->head; i!=NULL;i = i->next){
		printf("%d  ", i->data);
	}
//    printf("%d  ", l.head->next->data);  LAY GIA TRI TAI VI TRI BAT KY
	free(p);
	free(q);
	return 0;
}
