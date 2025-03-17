#include <iostream>

using namespace std;

class Node{
    public:
      int data;
      Node* next;
      Node* prev;
      Node(int value);
};

Node::Node(int value){
    data = value;
    next = nullptr;
    prev = nullptr;
}

class linkedList{
    public:
      int size();
      void addEnd(int value);
      void reckon();
      void out();
      float average();
      void insertPre(int pos, int value);
      void min();
      void removeX(int x);
      void removeAllX(int x);
      void remove(int pos);
      void sortASC();
      Node* search(int pos);
      void check();
      void quickSort(Node* l, Node* r);
      Node* partition(Node* l, Node* r);
      Node* timNode(Node* x);
      linkedList();
      Node* getHead();
      Node*getTail();
    private:
      Node* head;
      Node* tail;
     
};

linkedList::linkedList(){
    head = nullptr;
    tail = nullptr;
}

void linkedList::addEnd(int value){  
    Node* creat = new Node(value);
    if(head == nullptr) {
        head = creat;
        tail = creat;
    }
    else {
       creat->prev = tail;
       tail -> next = creat;
       tail = creat;
    }
}

int linkedList::size(){
    Node* temp = head;
    int dem = 0;
    while(temp!=nullptr){
        dem++;
        temp = temp->next;
    }
    return dem;
}

float linkedList::average(){
    float sum = 0;
    Node* temp = head;
    while(temp != nullptr){
        sum += temp->data;
        temp = temp->next;
    }
    return sum/size();
}

void linkedList::reckon(){
    Node* temp = head;
    int dem = 0;
    while(temp != nullptr){
        dem++;
        temp = temp ->next;
    }
    cout << "So phan tu cua danh sach la: " << dem << endl;
}

void linkedList::insertPre(int element, int value){
    // 1 2 5 6 9 
    if(head == nullptr) {
        cout << "Day rong!\n";
        return;
    }
     else {
    
    Node* current = head;
    while(current != nullptr){
        if(current->data  == element){
           Node* creat = new Node(value);
           creat->next = current->next;
           current->next = creat;
           return;
        }
        current = current->next;
    }
    }
}

Node* linkedList::search(int pos){
    if(pos > size()){
         cout << "NULL\n";
         return 0;
        }
    Node* temp = head;
    for(int i=0; i<pos-1; i++){
        temp = temp->next;
    }
    return temp;
}

void linkedList::min(){
    if(head == nullptr){
        cout << "Danh sach rong!\n";
        return;
        }
     else{
        int min = head->data;
        Node* temp = head->next;
        while(temp!=nullptr){
            if(temp->data < min) min = temp->data; 
            temp = temp->next; 
        }
        cout << "Phan tu nho nhat trong danh sach la: " << min << endl;

     }
}

void linkedList::removeX(int x){
    if(head == nullptr){
        cout << "Danh sach rong!\n";
        return;
    }
     else {
        if(head->data == x){
            head = head->next;
            return;
        }
        Node* temp = head;
        while(temp!=nullptr){
            if(temp->next->data == x){
                temp->next = temp->next->next;
            }
            break;
        }
     }
}

void linkedList::removeAllX(int x){
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    } else {
        Node* current = head;
        Node* previous = nullptr;

        while(current!=nullptr){
            if(current->data != x){
                previous = current;
                current = current->next;
            }
             else{
                if(previous == nullptr){
                    head = current->next;
                    delete head;
                    current = head;
                }
                 else {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                 }
             }
        }
    }

}

void linkedList::sortASC(){
    for(Node* i = head; i!=nullptr; i=i->next){
        Node* min = i;
        for(Node* j = i->next; j!=nullptr; j=j->next){
            if(j->data < min->data) min = j;
        }
        int temp = i->data;
        i->data = min->data;
        min->data = temp;

    }
    
}

void linkedList::check(){
    Node* temp = head;
   for(Node* i =head; i->next!=nullptr; i=i->next){
    for(Node* j =i->next; j!=nullptr; j=j->next){
        if(j->data < i->data) {
            cout << "Day khong tang!\n";
            return;
        }
    }
   }
    cout << "Day tang!\n";
}

void linkedList::out(){
    for(Node* i = head; i != nullptr; i= i->next){
        cout << i->data << " ";
    }
    cout << endl;
}

Node*linkedList::partition(Node* l, Node* r) {
    int pivot = r->data;
    Node* i = l->prev;

    for (Node* j = l; j != r; j = j->next) {
        if (j->data >= pivot) {
            i = (i == nullptr) ? l : i->next;
            swap(i->data, j->data);
        }
    }

    i = (i == nullptr) ? l : i->next;
    swap(i->data, r->data);
    return i;
}
  
// Performing quick sort in  the given linked list 
void linkedList::quickSort(Node* l, Node* r) {
    if (l != nullptr && l != r && l != r->next) {
        Node* pivot = partition(l, r);
        quickSort(l, pivot->prev);
        quickSort(pivot->next, r);
    }
}


Node* linkedList::getHead() {
    return head; // Trả về con trỏ đầu danh sách liên kết
}

Node* linkedList::getTail() {
    return tail; // Trả về con trỏ cuối danh sách liên kết
}


int main(){
    
    linkedList myList;

    // cout << "Nhap so luong phan tu(0 de thoat): ";
    int n;
    cin >> n;

    
    while (n!=0){
        cin >> n;
        if( n == 0) break;
         else {
            myList.addEnd(n);
         }
    }
    // myList.test();
    // myList.out();
    // cout << myList.average() << endl;
    // myList.reckon();
    // myList.insertPre(2, 5);
    // myList.out();

    // myList.search(3);
    // myList.min();
    // myList.removeAllX(2);
    // myList.sortASC();
   
    // myList.check();
    // myList.insertPre(2, 5);
    myList.quickSort(myList.getHead(), myList.getTail());

     myList.out();

    return 0;

}
