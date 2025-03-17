#include <iostream>

using namespace std;

class Node{
    public:
      int data;
      Node* next;
      Node(int value);
};

Node::Node(int value){
    data = value;
    next = nullptr;
}

class linkedList{
    public:
      int size();
      void addEnd(int value);//Thêm vào danh sách
      void reckon();//Đếm số lượng phần tử
      void out();//In 
      float average();//Trung bình  cộng
      void insertAft(int element, int value);//Thêm sau
      void insertBef(int element, int value);//Thêm trước
      void min();//Tìm nhỏ nhất
      void removeX(int x);//Xóa 1 phần tử X
      void removeAllX(int x);//Xóa tất cả phần tử X
      void remove(int pos);
      void sortASC();//Sắp xếp tăng dần
      void search(int pos);//Tìm kiếm phần tử
      void check();//Kiểm tra dãy có tăng hay không?
      linkedList();

    private:
      Node* head;
      Node* tail;
     
};

linkedList::linkedList(){
    head = nullptr;
    tail = nullptr;
}

void linkedList::addEnd(int value){ 
   //Hàm thêm cuối
    Node* creat = new Node(value);
    if(head == nullptr) {
        head = creat;
        tail = creat;
    }
    else {
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
    //Hàm đếm số phần tử trong danh sách
    Node* temp = head;
    int dem = 0;
    while(temp != nullptr){
        dem++;
        temp = temp ->next;
    }
    cout << "So phan tu cua danh sach la: " << dem << endl;
}

void linkedList::insertAft(int element, int value){
    //Hàm thêm sau các phần tử x
    if(head == nullptr) {
        cout << "Day rong!\n";
        return;
    }
    else{ 
        int dem = 0;//Kiểm tra trong danh sách có x hay không
        Node* current = head;
        while (current != nullptr) {
            if (current->data == element) {
            dem++;
            Node* newNode = new Node(value);//Cập nhật Node mới mang giá trị thêm sau mỗi lần thêm

            newNode->next = current->next;
            current->next = newNode;

            current = newNode; // Di chuyển current đến phần tử vừa chèn
            }
           current = current->next;
        } 
        if(dem == 0) cout << "Danh sach khong co gia tri " << element << endl;
    }
}

void linkedList::insertBef(int element, int value){
    //Hàm thêm trước các phần tử X
    Node* current = head;
    Node* prev = nullptr;
    int dem = 0;
    // Node pre đóng vai trò danh sách chính - Node current đóng vai trò duyệt phần tử - Hiểu : Pre = current - 1
    while (current != nullptr) {
        if (current->data == element) {
            dem ++;
            Node* newNode = new Node(value);
            if (prev != nullptr) { 
                newNode->next = prev->next;
                prev->next = newNode;
            } else { //THêm đầu 
                newNode->next = current;
                head = newNode;
            }
            prev = newNode;//Di chuyển pre đến phần tử vừa thêm
        }
        prev = current;//Di chuyển pre thêm 1 phần tử
        current = current->next;
    }
    if(dem = 0) cout << "Danh sach khong co gia tri " << element << endl;
}

void linkedList::search(int pos){
    //Hàm tìm phần tử ở vị trí x
    if(pos > size() or pos < 0){
         cout << "NULL\n";
         return;
        }
    Node* temp = head;
    for(int i=0; i<pos-1; i++){
        temp = temp->next;
    }
    cout << temp->data;
}

void linkedList::min(){
    //Hàm tìm phần tử có giá trị nhỏ nhất
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

void linkedList::removeX(int element){
    //Hàm xóa 1 phần tử có giá trị x
    if(head == nullptr){
        cout << "Danh sach rong!\n";
        return;
    }
    else {
        int dem = 0;
        if(head->data == element){
            dem ++;
            head = head->next;
            return;
        }
        Node* temp = head;
        while(temp!=nullptr){
            if(temp->next->data == element){
                dem ++;
                temp->next = temp->next->next;
            }
            break;
        }
        if(dem == 0) cout << "Danh sach khong co gia tri " << element << endl;
    }
    
}

void linkedList::removeAllX(int element){
    //Hàm xóa tất cả các phần tử có giá trị x
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    } 
    else {
        int dem = 0;
        Node* current = head;
        Node* previous = nullptr;
       //Tương tự như hàm thêm trước. Tạo 2 Node để dễ quản lí hơn
        while(current!=nullptr){
            if(current->data != element){
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
        if(dem == 0) cout << "Danh sach khong co gia tri " << element << endl;
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


int main(){
    
    linkedList myList;

    int n;
    cin >> n;
    cout << "Them phan tu vao danh sach. Nhan 0 de dung\n";
    while (n!=0){
        cin >> n;
        if( n == 0) break;
         else myList.addEnd(n);
    }

    myList.out();

    cout << "Trung binh danh sach: " << myList.average() << endl;

    myList.check();
    myList.reckon();

    cout << "\nThem 5 vao truoc 2\n";
    myList.insertBef(2, 5);
    myList.out();

    cout << "Them 6 vao sau 3\n";
    myList.insertAft(3, 6);
    myList.out();

    cout << "Phan tu thu ba co gia tri: "; 
    myList.search(3);
    
    cout << endl;
    myList.min();
    
    cout << "Xoa cac gia tri 11 \n"  ;
    myList.removeAllX(11);
    myList.out();

    cout << "Sap xep tang dan\n";
    myList.sortASC();
    myList.out();

    return 0;

}
