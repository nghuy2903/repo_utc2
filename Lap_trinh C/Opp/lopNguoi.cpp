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
    int i = 1;
    while (temp != NULL && i < q - 1)
    {
        temp = temp->next;
        ++i;
    }
    if (temp != NULL && i == q - 1)
    {
        p->next = temp->next;
        temp->next = p;
    }
    else
        addHead(a);
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
    Node *temp = head;
    Item i = 1;
    if (x > size)
        return 0;
    while (temp != NULL && i < x - 1)
    {
        temp = temp->next;
        ++i;
    }
    if (temp != NULL && i == x - 1)
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
    for (Node *i = head; i != NULL; i = i->next)
    {
        cout << i->data;
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
    // Item n;
    // cin >> n;
    // while(n!=0)
    // {
    //     Item r = n % 2;
    //     a.addHead(r);
    //     n /= 2;
    // }
    a.addHead(5);
    a.Print();
    a.CleanUp();
    
    return 0;
}