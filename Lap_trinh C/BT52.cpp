#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}node;
typedef struct List{
	node *head;
}list;
node* createNode(int d){
	node *p = (node*)malloc(sizeof(node));
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

void insert(list *l, node *p,int n, int k) {
	if( k > n+1){
		printf("Khong them duoc!");
		return;
	}
	if(k == 1) {
		themDau(l, p);
		return;
	}
	
	node *temp = l->head;
	for(int i = 0; i < k - 2; i++) {
		temp = temp->next;
	}
	
	p->next = temp->next;
	
	temp->next = p;
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
	node *h = (node*)malloc(sizeof(node));
	
	p=createNode(5);
	q=createNode(15);
	h=createNode(7);
	// them p vao dau danh sach
	list *l = (list*)malloc(sizeof(list));
	
	l->head = NULL;
	
	themDau(l,p);
	
	themDau(l,q);
	
//	insert(l, h, 2 , 3);
	
	
	for(node *i=l->head;i!=NULL;i=i->next){
		
		printf("%d  ",i->data);
	}

	free(p);
	free(q);
	free(h);
	free(l);
	
	
	return 0;
}

