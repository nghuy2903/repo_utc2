#include <iostream>
#include <algorithm>

using namespace std;

class Node {
  public:
    int data;
    Node* next;
	Node* prev;
    Node (int value);
};

Node::Node(int value){
	data = value;
	next = nullptr;
	prev = nullptr;
}

class LinkedList {
  
  public:
    LinkedList();
    void append(int value); //
    void prepend(int vlaue);
	void removeLast();
	void insert(int value, int locus);
    void remove(int locus);
	void sortASC();
    void print();
    void removeFist();
	int countNode();
	void deleteNodeAtPosition(int pos);
	void min(){
		if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return; // Kết thúc hàm khi danh sách rỗng
        } 
		else {
        int min = head->data;
        Node* temp = head->next;
        while (temp != nullptr) {
            if (temp->data < min) min = temp->data; 
            temp = temp->next; 
        }
        cout << "Phan tu nho nhat trong danh sach la: " << min << endl;
        }
	}
	void Menu();
	void out();
	void deleteNode(int vitri);
  private: 
    Node* head;
	Node* tail;
};

LinkedList::LinkedList(){
	head = nullptr;
	tail = nullptr;
}

void LinkedList::append(int value){
	Node *newNode = new Node(value);
	if(head == nullptr){
      head = newNode;
	  tail = newNode;
	}
	 else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	 }
}

void LinkedList::prepend(int value){
	Node* newNode = new Node(value);
	if(head == nullptr){
        head = newNode;
        tail = newNode;
	}
	else{
		newNode -> next = head;
		head = newNode;
	}
}

void LinkedList::removeLast(){
    Node* temp = tail;
   if(head == nullptr) cout << "Total array!" << endl;
    else {
		Node* current = head;
		while(current->next != tail){
			current = current->next;
		}
		current->next = nullptr;
		current = tail;
        delete(temp);
	}

}

void LinkedList::insert(int value, int locus){
	if(head == nullptr) cout << "Total array!" << endl;
     else if(locus == 1) {
        prepend(value);
        return;
        }
	  else{
		Node* current = head;
		for(int i=1; i<locus-1; i++){
			current = current->next;
		}
		Node* creatNode = new Node(value);
		creatNode -> next = current -> next;
		current->next = creatNode;
        
	 }
	
}

void LinkedList::remove(int locus){
	if(head == nullptr) cout << "Total array!" << endl;
	 else {
		Node* current = head;
		for(int i=1; i<locus-1; i++){
            current = current->next;
		}
        Node* temp = current->next;
		current->next = current->next->next;
        delete(temp);
	 }
}

void LinkedList::removeFist(){
    Node* temp = head;
    head = head->next;
    delete(temp);
}

void LinkedList::sortASC(){
    for (Node* i = head; i->next != nullptr; i=i->next){
        Node* max = i;
        for (Node* j = i->next; j !=nullptr; j=j->next){
            if(j->data > max->data) max = j;
        }
        int temp = i->data;
        i->data = max->data;
        max->data = temp;
    }
}

void LinkedList::print(){
	Node* current = head;
	while (current != nullptr){
		cout << current -> data << "\t";
        current = current -> next;
	}
	cout << endl;
}

void LinkedList::Menu(){
	int n;
	    cout << "\t" << "MENU" << endl;
		cout << "1.In mang" << endl << "2.Them dau" << endl << "3.Them cuoi" << endl << "4.Them bat ky" << endl;
		cout << "5. Xoa dau" << endl << "6. Xoa cuoi" << endl << "7.Xoa bat ky" << endl ;
		cout<<  "8.Sap xep" << endl << "0.Thoat" << endl;
	do{
		cout << "Chon: " << endl;
		cin >> n;
		switch(n){
			case 1: 
			  print();
			  break;
			case 2: 
			  int x;
			  cout << "Nhap gia tri them: ";
			  cin >> x;
			  prepend(x);
			  break;
			case 3: 
			  int y; 
			  cout << "Nhap gia tri them: ";
			  cin >> y;
			  append(y);
			  break;
			case 4: 
			  int value, position;
			  cout << "Nhap gia tri them : ";
			  cin >> value;
			  cout << "Nhap vi tri them: ";
			  cin >> position;
			  insert(value, position);
			  break;
			case 5: 
			  removeFist();
			  break;
			case 6: 
			  removeLast();
			  break;
			case 7: 
			  int pos;
			  cout << "Nhap vi tri xoa: " << endl;
			  cin >> pos;
			  remove(pos);
			  break;
			case 8:
			  sortASC();
			  break;
			case 0: 
			  cout << "Thoat chuong trinh" << endl;
			  break;
			default:
			  cout << "Nhap loi! Moi nhap lai" << endl;
			  break;

		}
	} while(n!=0);
}

void LinkedList::out(){
	cout << tail->prev->data;
	return;
}

int LinkedList::countNode(){
	int count = 0;
	Node* temp = head;
	while(temp!=nullptr){
		count++;
		temp = temp->next;
	}
	return count;
}

void LinkedList::deleteNode(int pos){
	if(pos == 1){
		removeFist();
		return;
	}
	if(pos == countNode()){
	    removeLast();
		return;
	}
	Node* current = head;
	for(int i=1; i<pos - 1; i++){
        current = current->next; // Di chuyển tới Node trước node cần xóa
	}
	Node* temp = current->next; // Node cần xóa
	current->next = temp->next;
	temp->next->prev = current;
	delete temp;
}

void LinkedList::deleteNodeAtPosition(int position) {
        Node* current = head;
        int currentPosition = 1;
		 if (!current || position > countNode()) {
            std::cout << "Node not found at position " << position << std::endl;
            return;
        }

        while (currentPosition < position) {
            current = current->next;
            currentPosition++;
        }

        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        }
		else {
			current->prev = tail;
		}

        delete current;
    }


int main() {
    LinkedList myList;
    // // myList.Menu();
	// myList.min();
	myList.append(5);
	myList.append(15);
	myList.append(20);
	myList.append(25);
	myList.append(30);
	myList.append(26);
	myList.append(28);
	myList.deleteNodeAtPosition(8);

	myList.print();


    return 0;
}
