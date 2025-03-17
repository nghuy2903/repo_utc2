#include <iostream>
using namespace std;
typedef int Item;

class Node;

class List;

class Node
{
    Item data;
    Node *next;

public:
    Node()
    {
        next = NULL;
    }
    Node(Item a, Node *p) : data(a) { next = p; }
    friend List;
};

class List
{
    Node *head;
    Node *tail;
    Item size;

public:
    List()
    {
        head = tail = NULL;
        size = 0; 
    };
    ~List()
    {
        CleanUp();
    }
    Node *createNode(Item x);
    bool isEmpty() const;
    bool isMember(Item x) const;
    void addHead(Item a);
    void addTail(Item a);
    void After(Item q, Item a);
    Item deleteHead();
    Item deleteElement(Item x);
    void CleanUp();
    int Cout() const;
    void Print() const;
};

Node *List::createNode(Item x)
{
    Node *p = new Node();
    if (p == NULL)
    {
        cout << "fail";
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

bool List::isEmpty() const
{
    return head == NULL;
}

void List::addHead(Item a)
{
    Node *p = createNode(a);
    if (head == NULL)
    {
        head = p;
        tail = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
    size++;
}

void List::addTail(Item a)
{
    Node *p = createNode(a);
    if (head == NULL)
    {
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
    size++;
}
void List::After(Item q, Item a)
{
    Node *p = createNode(a);
    Node *temp = head;
    bool check = false;
    while (temp != NULL)
    {
        if(temp->data == q) {
            check = true;
            break;
        }
        temp = temp->next;
    }
    if (check)
    {
        p->next = temp->next ;
        temp->next = p;
        if(temp == tail){
            tail = p;
        } 
    }
    else addHead(a);
    size++;
}

Item List::deleteHead()
{
    Node *temp = head;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        head = head->next;
        delete temp;
    }
    size--;
    return 1; // Indicate success
}

Item List::deleteElement(Item x)
{
    if(head->data == x){
        deleteHead();
        return 1;
    }
    Node *temp = head;
    bool check = false;
    while (temp != NULL)
    {
        if(temp->next->data == x){
            check = true;
            break;
        }
        temp = temp->next;
    }
    if (check)
    {
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
    size--;
    return 1; // Indicate success
}

void List::Print() const
{
    if(!head){
        cout << "blank";
        return;
    }
    for (Node *i = head; i != NULL; i = i->next)
    {
        cout << i->data << " ";
    }
}

void List::CleanUp()
{
    Node *p;

    while (!isEmpty())
    {
        deleteHead();
    }
}

int main()
{
    List a;

    int n;
    do{
        int x, y,z; 
        cin >> n;
        if(n == 6) break;
        if(n==5) {
            a.deleteHead();
            continue;
        }
        if(n!=2){cin >> x;}
        else { cin >> y >> z;}

        if(n == 0) a.addHead(x);
        else if(n==1) a.addTail(x);
        else if(n==2) a.After(y,z);
        else if ( n==3) a.deleteElement(x);
        
    }while (n!=6);

    a.Print();

    a.CleanUp();
    
    return 0;
}