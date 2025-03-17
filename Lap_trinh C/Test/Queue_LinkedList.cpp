#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

class Queue{
	private:
		Node *head;
		Node *tail;
		int size;
	public:
		Queue();// khoi tao
		bool isEmpty();
		int Size();
		void enqueue(int x);
		void dequeue();
		void show();
		int front();
		int back();
};

Queue::Queue(){
	head=tail=NULL;
	size=0;
}

bool Queue::isEmpty(){
	if(size==0)
		return true;
	else
		return false;
}

void Queue::enqueue(int x){
	Node *p= new Node();
	p->data=x;
	p->next=NULL;
	
	if(head==NULL){
		head=tail=p;
	}
	else{
		tail->next=p;
		tail=p;
	}
	size++;
}

void Queue::dequeue(){
    if(head == nullptr){
        cout << "Queue null!\n";
        return;
    }
	size--;
    Node* temp = head;
    head = head->next;
    delete temp;
}

int Queue::back(){
	return tail->data;
}

int Queue::front(){
	return head->data;
}

int Queue::Size(){
   return size;
}

void Queue::show(){
    if(head == nullptr) {
        cout << "Queue null!\n";
        return ;
    }
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
	cout << endl;
}

int main(){
    Queue myQueue;
	
    myQueue.enqueue(5);
    myQueue.enqueue(15);
    myQueue.enqueue(20);
    myQueue.dequeue();
    myQueue.show();

    return 0;
}