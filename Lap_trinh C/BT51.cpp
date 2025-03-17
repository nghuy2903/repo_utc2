#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
}node;
typedef struct List{
	node *head;
}list;
node* createNode(int d){
	Node *p = (node*)malloc(sizeof(node));
	p->data=d;
	p->next=NULL;
	return p;
}

void themDau(list *l, node *p){
	if(l->head==NULL){
		l->head=p;
	}
	else{
		p->next=l->head;
		l->head=p;	
	}
}
void themCuoi(list *l, node *p){
	if(l->head==NULL)
		l->head=p;
	else{
		node *t = l->head;
		while(t->next!=NULL)
			t=t->next;
		t->next=p;
	}
}
int main(){
	node *p =(node*)malloc(sizeof(node));
	node *q = (node*)malloc(sizeof(node));
	p=createNode(5);
	q=createNode(15);
	// them p vao dau danh sach
	list *l = (list*)malloc(sizeof(list));
	l->head = NULL;
	themDau(l,p);
	themDau(l,q);
	
	for(node *i=l->head; i != NULL; i = i->next){
		printf("%d  ",i->data);
	}
}
