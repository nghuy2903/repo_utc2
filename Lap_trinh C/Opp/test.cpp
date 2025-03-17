#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value);
};

Node::Node(int value) {
    data = value;
    next = nullptr;
}

class linkedList {
public:
    void addFirst(int value);
    void addEnd(int value);
    void out();

    void insertAfter(int afterValue, int value);
    void removeX(int x);
    void removeFirst();

    linkedList();
    ~linkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

private:
    Node* head;
    Node* tail;
};

linkedList::linkedList() {
    head = nullptr;
    tail = nullptr;
}

void linkedList::addFirst(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}

void linkedList::addEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void linkedList::insertAfter(int afterValue, int value) {
    Node* current = head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }

    if(current == nullptr){
        addFirst(value);
        return;
    }

    if(current == tail){
        addEnd(value);
        return;
    }
    else{
    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
    }
}

void linkedList::removeX(int x) {
    if (head == nullptr) {
        return;
    }

    if (head->data == x) {
        removeFirst();
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != x) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        previous->next = current->next;
        delete current;
    }
}


void linkedList::removeFirst() {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void linkedList::out() {
    if(head == nullptr) {
        cout << "blank\n";
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    linkedList a;

    int n, x, y,z; 
    do{
        
        cin >> n;
        if(n>6 || n<0) continue;
        if(n == 6) break;
        if(n==5) {
            a.removeFirst();
            continue;
        }
        if(n!=2){cin >> x;}
        else { cin >> y >> z;}

        if(n == 0) a.addFirst(x);
        else if(n==1) a.addEnd(x);
        else if(n==2) a.insertAfter(y,z);
        else if (n==3) a.removeX(x);
       a.out();
    }while (n!=6);

     

    a.~linkedList();
    return 0;
}
