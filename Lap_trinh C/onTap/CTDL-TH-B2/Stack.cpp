#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node(char value){
            data = value;
            next = nullptr;
        }
};

class Stack{
        Node* head;
    public:
        void push(char value);
        char pop();
        bool isEmpty();
        void printStack();
        Stack(){
            head = nullptr;
        }
        ~Stack(){
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }    
        }
};

bool Stack::isEmpty(){
    return head == nullptr ? true : false;
}

void Stack::push(char value){
    Node* newNode = new Node(value);

    if(isEmpty()){
        head = newNode;
        return;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

char Stack::pop(){
    Node* temp = head;
    char c = temp->data;
    head = head->next;
    delete temp;
    return c;
}

void Stack::printStack(){
    Node* temp = head;
    while (temp!=nullptr)
    {
        cout << temp->data;
        temp = temp->next;
    }

    cout << endl;
}

void chuyenHeDem(){
    stack<int> a;
    int n, temp;
    label:  cout << "Nhap so he thap phan: ";
    cin >> n; temp = n;
    if(n<0){
        cout << "Nhap lai so(n>0)!\n";
        goto label;
    }
  
    while (n!=0)
    {
        a.push(n%2);
        n = n/2;
    }

    cout << "So he nhi phan: ";

    if(temp==0){
        cout << 0;
        return;
    }

    while(!a.empty()){
        cout << a.top();
        a.pop();
    }
    cout << endl;

    a.~stack();
}

bool check(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == ')' || c == '(' || c == '^') return true;
     else return false;
}

bool toanTu(char c){
    if(c == ')') return true;
    else return false;
}

int doUuTien(char c){
    if(c == '+' || c == '-') return 1;
     else if(c == '*' || c == '/' ) return 2;
      else if(c == '^') return 3;
       else if( c == '(') return 0;

}

void trungToSangHauTo(){
    string s;
    cout << "Nhap bieu thuc: ";
   cin >> s;

    Stack a;
    char res[15];
    int i = 0, temp;
    char c;

    for(auto x : s){
        if(!check(x)){ // Nếu x là toán hạng thêm vào output
            res[i++] = x;
            continue;
        } 
        else{
            if(x != ')'){
                if(a.isEmpty() || x == '('){ //Nếu Stack rỗng hoặc '(' thì thêm vào stack
                    a.push(x);
                    continue;
                }

                int m = doUuTien(x); // Xét độ ưu tiên của x
                c = a.pop();
                int n = doUuTien(c);// Xét độ ưu tiên của toán tử trong stack
                
                while (!a.isEmpty() && n>=m) // Lấy hết các toán tử có độ ưu tiên trong stack lớn hơn input sang output
                {
                    res[i++] = c;
                    c = a.pop();
                    n = doUuTien(c);
                }

                if(a.isEmpty() && n>=m){ // Trường hợp trong stack có 1 toán tử có độ ưu tiên lớn hơn toán tử trong input
                    res[i++] = c;
                    a.push(x);
                    continue;
                }
                // Trường hợp toán tử input lớn hơn toán tử stack
                a.push(c);
                a.push(x);
            }
            else{ // Khi gặp ')' thì lấy tất cả toán tử trong stack cho đến khi gặp '('
                c = a.pop();
                while(c!='('){
                    res[i++] = c;
                    c = a.pop();
                }
            }
        }
    }
    //Lấy toán tử còn lại(nếu có) trong stack
    while (!a.isEmpty())
    {
        res[i++] = a.pop();
    }      
    
    temp = i;
    cout << "Bieu thuc hau to: ";

    for(i=0; i<temp; i++){
        cout << res[i];
    }
    cout << endl;
}

int phepTinh(char c){
    if(c == '+') return 1;
     else if(c == '-') return 2;
      else if(c == '*') return 3;
       else if(c == '/') return 4;
        else return 5;
}

void tinhGiaTriHauTo(){
    stack<int> a;
    string s;
    cout << "Nhap bieu thuc: ";
   cin >> s;

    int res;
    int y,z,t;
    for(auto x : s){
        if(x >= '0' && x <= '9') {
            int temp = x - '0';
            a.push(temp);
            // continue;
        }  
        else{
            y = a.top();
            a.pop();
            z = a.top();
            a.pop();
            t = phepTinh(x);
            if(t == 1) a.push( y+z);
            else if(t == 2) a.push( z-y);
            else if(t == 3) a.push( y*z);
            else if(t == 4) a.push( z/y);
            else a.push( pow(z,y));
        }
        
    }
    cout << "Gia tri bieu thuc hau to: " << a.top() << endl;;
    a.pop();
}


int main(){

    int n;

    do{
        system("cls");
        cout << "\n	        \t\tMENU           ";
        cout << "\n	+---------------------------------------------------+";
        cout << "\n	| [1]. Chuyen doi thap phan sang nhi phan           |";
        cout << "\n	| [2]. Chuyen doi bieu thuc trung to sang hau to    |";
        cout << "\n	| [3]. Tinh gia tri bieu thuc hau to                |";
        cout << "\n	| [0]. Thoat                                        |";
        cout << "\n	+---------------------------------------------------+\n";

        cout << "Chon: ";
        cin >> n;
        switch (n)
        {
        case 1:
            chuyenHeDem();
            system("pause");
            break;
        case 2:
            trungToSangHauTo();
            system("pause");
            break;
        case 3:
            tinhGiaTriHauTo();
            system("pause");
            break;
        case 0:
        default:
            break;
        }
    }while (n!=0);
    


    return 0;
}