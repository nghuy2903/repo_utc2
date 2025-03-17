#include<iostream>

using namespace std;

typedef struct NODE{
	int data;
	NODE *next;
}Node;

class Stack{
	private:
		Node *top;
		int size;
	public:
		Stack();
		Node* createNode(int x);
		bool isEmpty();
		void push(int x);
		int pop();
		int peek();
		void print();
};

Stack::Stack(){
	top=NULL;
	size=0;
}

Node* Stack::createNode(int x){
	Node *p = new Node();
	p->data=x;
	p->next=NULL;
	return p;
}

bool Stack::isEmpty(){
	if(size==0)
		return true;
	else
		return false;
}

void Stack::push(int x){
	Node *p = createNode(x);
	if(isEmpty()==true){
		top=p;
	}
	else{
		p->next=top;
		top=p;
	}
	size++;	
}

int Stack::pop(){
	int data = top->data;
	Node *p = top;
	top=top->next;
	delete p;
	size--;
	return data;
}

void Stack::print(){
	for(Node *i=top;i!=NULL;i=i->next){
		cout<<i->data<<"  ";
	}
}

int main(){
	Stack s;
	if(s.isEmpty()==true)
		cout<<"Stack is empty";
	else
		cout<<"Stack is not empty";
	s.push(5);
	s.push(10);
	s.push(20);
	s.pop();
	s.push(50);
	cout<<"\nElement stack: ";
	s.print();

	return 0;
}