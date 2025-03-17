#include <iostream>


using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;
        Node* tail;

    public:
/*
    1.Khai báo cấu trúc dữ liệu cho danh sách liên kết đơn số nguyên
    2.Khởi tạo danh sách liên kết đơn
    3.Kiểm tra danh sách có rỗng hay không
    4.Tạo 1 node mới có kiểu số nguyên
    5.Thêm đầu
    6.Thêm cuối
    7.Nhập danh sách
    8.In danh sách
    9.Thêm 1 node mới vào sau node q
    10.Thêm 1 node mới vào trước node q
    11.Xóa đầu
    12.Xóa cuối
    13.Xóa 1 node sau node q
    14.Xóa 1 node có khóa k cách 1
    15.Xóa 1 node có khóa k cách 2
    16.Xóa 1 node tại vị trí n
    17.Lấy node đầu tiên ra khỏi danh sách
    18.Tìm kiếm phần tử có data = k
    19.Đếm số lượng các phần tử trong danh sách (tính độ dài)
    20.Tìm số lớn nhất trong danh sách liên kết đơn
    21.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp đổi chỗ trực tiếp
    22.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp chọn trực tiếp
    23.Sắp xếp danh sách liên kết đơn tăng dần bằng sắp xếp nổi bọt
    24.Hủy toàn bộ danh sách
    25.Nối hai danh sách liên kết đơn l1 và l2 lại thành danh sách liên kết đơn l sao cho khi sau khi nối vẫn đảm bảo thứ tự tăng dần
    26.Thêm một nút vào danh sách (giả sử danh sách đã có thứ tự tăng dần) sao cho sau khi thêm danh sách vẫn đảm bảo có thứ tự tăng dần.
    27.Đảo ngược danh sách
    28.In danh sách đảo ngược dùng đệ quy
    29.Đảo ngược danh sách liên kết dùng đệ quy*/

    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const;// Kiểm tra danh sách có rỗng hay không
    void addAtBeginning(int value);// Thêm node vào đầu danh sách
    void addAtEnd(int value);// Thêm node vào cuối danh sách
    void printList() const;// In danh sách
    Node* search(int key) const;// Tìm kiếm phần tử có giá trị k trong danh sách
    void inPutList();//Nhập danh sách
    void addAfter(int p, int value);//Thêm 1 node vào sau q
    void addBefore(int p, int value);// Thêm 1 node mới vào trước node q
    int removeFirst();//Xóa đầu
    int removeLast();//Xóa cuối
    void removeAfter(int q);//Xóa Node sau Node có giá trị q
    void removeByKey1(int key);//Xóa Node cách 1
    void removeByKey2(int key);//Xóa Node cách 2
    void deleteNodeAtPosition(int position);//Xóa 1 Node tại vị trí n
    void popFront();//Lấy Node head ra khỏi danh sách
    Node* Search(int k);//Tìm Node có gía trih k
    int Length();//Đếm số lượng các phần tử(tính dộ dài)
    void findMax();//Tìm phần tử lớn nhất
    void bubbleSort();//Sắp xếp nổi bọt
    void selectionSort();//Sắp xếp chọn
    void insertionSort();//Sắp chèn
    void addNodeSorted(int value);//Thêm Node vẫn giữ tính tăng dần
    void mergeSortedLists(const LinkedList &l);//Nối 2 danh sách vẫn giữ tính tăng dần
    void clear();//Xóa toàn bộ danh sách
    void reverseList();//Hàm đảo ngược danh sách
    void printReverseRecursive();//Hàm in danh sách đảo ngược bằng đệ quy
    void printReverseRecursiveHelper(Node* current);//Hàm đệ quy in danh sách đảo ngược

};
    

// Kiểm tra danh sách có rỗng hay không
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Thêm node vào đầu danh sách
void LinkedList::addAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}

// Thêm node vào cuối danh sách
void LinkedList::addAtEnd(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

// Tìm kiếm phần tử có giá trị k trong danh sách
Node* LinkedList::search(int key) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;  // Trả về nullptr nếu không tìm thấy
}

void LinkedList::addAfter(int qData, int value) {
    Node* current = head;
    while (current != nullptr && current->data != qData) {
        current = current->next;
    }

    if (current != nullptr) {
        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;

        // Nếu node mới được thêm là node cuối, cập nhật tail
        if (current == tail) {
            tail = newNode;
        }
    }
}

// Thêm 1 node mới vào trước node q
void LinkedList::addBefore(int qData, int value) {
    // Nếu qData là giá trị của node đầu tiên
    if (head != nullptr && head->data == qData) {
        addAtBeginning(value);
        return;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr && current->next->data != qData) {
        current = current->next;
    }

    if (current != nullptr && current->next != nullptr) {
        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Xóa đầu danh sách
int LinkedList::removeFirst(){
    if (isEmpty()) return 0;

    Node* temp = head;
    head = head->next;
    delete temp;

    // Nếu danh sách trở nên rỗng, cập nhật tail
    if (head == nullptr) {
        tail = nullptr;
    }
    return 1;
}

// Xóa cuối danh sách
int LinkedList::removeLast() {
    if (isEmpty()) return 0;

    if (head == tail) {
        // Nếu danh sách chỉ chứa một node, xóa node và cập nhật head và tail
        delete head;
        head = tail = nullptr;
        return 1;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
    return 1;
}

// Xóa 1 node sau node q
void LinkedList::removeAfter(int qData) {
    Node* current = head;

    // Tìm node có giá trị qData
    while (current != nullptr && current->data != qData) {
        current = current->next;
    }

    // Nếu node có giá trị qData không tồn tại
    if (current == nullptr || current->next == nullptr) {
        cout << "Khong tim thay node co gia tri " << qData << " hoac khong co node sau node q.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    // Nếu node bị xóa là node cuối, cập nhật tail
    if (current->next == nullptr) {
        tail = current;
    }
}

// Xóa 1 node có khóa k cách 1
void LinkedList::removeByKey1(int key) {
    if (isEmpty()) {
        cout << "Danh sach rong. Khong the xoa.\n";
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;

        // Nếu danh sách trở nên rỗng, cập nhật tail
        if (head == nullptr) {
            tail = nullptr;
        }
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != key) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;

        // Nếu node bị xóa là node cuối, cập nhật tail
        if (current->next == nullptr) {
            tail = current;
        }
    }
}

// Xóa 1 node có khóa k cách 2
void LinkedList::removeByKey2(int key) {
    Node* current = head;
    Node* prev = nullptr;

    // Tìm node có giá trị k
    while (current != nullptr && current->data != key) {
        prev = current;
        current = current->next;
    }

    // Nếu node có giá trị k không tồn tại
    if (current == nullptr) {
        cout << "Khong tim thay node co gia tri " << key << ". Khong the xoa.\n";
        return;
    }

    // Xóa node
    if (prev == nullptr) {
        // Node cần xóa là node đầu tiên
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;

    // Nếu node cần xóa là node cuối cùng, cập nhật tail
    if (current == tail) {
        tail = prev;
    }
}

// Hàm xóa 1 node tại vị trí n
void LinkedList::deleteNodeAtPosition(int position) {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;//Nếu danh sách rỗng khi xóa đầu thì tail bằng rỗng
        }
        cout << "Node tai vi tri thu " << position << " da xoa." << endl;
        return;
    }

    Node* current = head;
    int count = 0;
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Node at position " << position << " does not exist." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    if (current->next == nullptr) {
        tail = current;
    }

    cout << "Node at position " << position << " deleted." << endl;
}

// Hàm lấy node đầu tiên ra khỏi danh sách
void LinkedList::popFront() {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    cout << "Node dau tien "<< head->data  << endl;
    Node* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
    cout << "Node dau tien da duoc lay ra!" << endl;
    
}

// Hàm tìm kiếm phần tử có data = k
Node* LinkedList::Search(int k) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == k) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Không tìm thấy
}

// Hàm đếm số lượng các phần tử trong danh sách (tính độ dài)
int LinkedList::Length() {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Hàm tìm số lớn nhất trong danh sách
void LinkedList::findMax() {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return ; // Giả sử danh sách không có số âm
    }

    int maxElement = head->data;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->data > maxElement) {
            maxElement = current->data;
        }
        current = current->next;
    }
    cout << "Phan tu lon nhat: " << maxElement << endl;
}

// Hàm sắp xếp danh sách bằng sắp xếp nổi bọt (Bubble Sort)
void LinkedList::bubbleSort() {
    if (head == nullptr) {
        cout << "List is empty. Cannot sort." << endl;
        return;
    }

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data > j->next->data) {
                // Đổi chỗ hai node
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

// Hàm sắp xếp danh sách bằng sắp xếp chọn trực tiếp (Selection Sort)
void LinkedList::selectionSort() {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    for (Node* i = head; i != nullptr; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (j->data < min->data) {
                min = j;
            }
        }

        // Đổi chỗ node có giá trị nhỏ nhất với node hiện tại
        int temp = i->data;
        i->data = min->data;
        min->data = temp;
    }
}

// Hàm sắp xếp danh sách bằng sắp xếp chèn (Insertion Sort)
void LinkedList::insertionSort() {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    Node* sorted = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;

        // Nếu danh sách đã sắp xếp rồi hoặc danh sách mới
        if (sorted == nullptr || sorted->data >= current->data) {
            // Chèn node vào đầu danh sách đã sắp xếp
            current->next = sorted;
            sorted = current;
        } else {
            Node* search = sorted;
            while (search->next != nullptr && search->next->data < current->data) {
                search = search->next;
            }
            // Chèn node vào vị trí phù hợp trong danh sách đã sắp xếp
            current->next = search->next;
            search->next = current;
        }

        current = next;
    }

    head = sorted;
}

// Hàm thêm node mới vào danh sách với thứ tự tăng dần
void LinkedList::addNodeSorted(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr || head->data > value) {
        // Thêm vào đầu danh sách nếu danh sách rỗng hoặc giá trị mới nhỏ hơn giá trị đầu tiên
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }

        // Thêm vào giữa danh sách
        newNode->next = current->next;
        current->next = newNode;

        // Nếu newNode là node cuối cùng, cập nhật tail
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
}

// Hàm nối hai danh sách sao cho vẫn giữ thứ tự tăng dần
void LinkedList::mergeSortedLists(const LinkedList& otherList) {
    Node* current1 = head;
    Node* current2 = otherList.head;

    LinkedList mergedList;  // Danh sách tạm để lưu kết quả

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data < current2->data) {
            mergedList.addNodeSorted(current1->data);
            current1 = current1->next;
        } else {
            mergedList.addNodeSorted(current2->data);
            current2 = current2->next;
        }
    }

    // Nếu một trong hai danh sách còn phần tử, thêm phần còn lại vào danh sách kết quả
    while (current1 != nullptr) {
        mergedList.addNodeSorted(current1->data);
        current1 = current1->next;
    }

    while (current2 != nullptr) {
        mergedList.addNodeSorted(current2->data);
        current2 = current2->next;
    }

    // Xóa toàn bộ danh sách hiện tại
    clear();

    // Sao chép danh sách kết quả vào danh sách hiện tại
    Node* currentMerged = mergedList.head;
    while (currentMerged != nullptr) {
        addNodeSorted(currentMerged->data);
        currentMerged = currentMerged->next;
    }
}

// Hàm xóa toàn bộ danh sách
void LinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}


// Hàm đảo ngược danh sách
void LinkedList::reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}


// Hàm in danh sách đảo ngược sử dụng đệ quy
void LinkedList::printReverseRecursive() {
    printReverseRecursiveHelper(head);
    std::cout << std::endl;
}

// Hàm đệ quy giúp in danh sách đảo ngược
void LinkedList::printReverseRecursiveHelper(Node* current) {
    if (current == nullptr) {
        return;
    }

    // Đệ quy để in danh sách từ phần tử tiếp theo đến phần tử đầu tiên
    printReverseRecursiveHelper(current->next);

    // In giá trị của phần tử hiện tại
    std::cout << current->data << " ";
}

//Nhập danh sách
void LinkedList::inPutList(){
    cout << "Nhap so luong phan tu: ";
    int n;cin>>n;

    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        addAtEnd(x);
    }

}

// In danh sách
void LinkedList::printList() const {
    Node* current = head;
    if(!current){
        cout << "NUll\n";
        return;
    }
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Menu(){
    LinkedList myList;
    LinkedList l2;
    int n, x, y;
    do{
    system("cls");
    cout << "\n	        \t\tMENU           ";
    cout << "\n	+------------------------------------------------------------------------------------+";
    cout << "\n	| [1]. Them dau danh sach              | [6]. Xoa Node dau                           |";
    cout << "\n	| [2]. Them cuoi danh sach             | [7]. Xoa Node cuoi                          |";
    cout << "\n	| [3]. In danh sach                    | [8]. Xoa Node sau q                         |";
    cout << "\n	| [4]. Them Node vao sau gia tri q     | [9]. Xoa Node co khoa k C1                  |";
    cout << "\n	| [5]. Them Node vao truoc gia tri q   | [10]. Xoa Node co khoa k C2                 |";
    cout << "\n	| [11]. Xoa Node tai vi tri n          | [17]. Bubble Sort                           |";
    cout << "\n	| [12]. Lay Node dau tien              | [18]. Selection Sort                        |";
    cout << "\n	| [13]. Nhap danh sach Node            | [19]. Insertion Sort                        |";
    cout << "\n	| [14]. Tim Node co gia tri k          | [20]. Them Node(dam bao tinh tang dan)      |";
    cout << "\n	| [15]. Dem cac phan tu theo do dai    | [21]. Noi 2 danh sach(dam bao tinh tang dan)|";
    cout << "\n	| [16]. Tim phan tu lon nhat           | [22]. In danh sach dao nguoc                |";
    cout << "\n	| [23]. In danh sach dao nguoc(de quy) |                                             |";
    cout << "\n	+------------------------------------------------------------------------------------+\n";
    

    

        cout << "Chon: ";
        cin >> n;
        switch(n){
        case 1:
            cout << "Nhap gia tri them: \n";
            cin >> x;
            myList.addAtBeginning(x);
            system("pause");
            break;
        case 2:
            cout << "Nhap gia tri them\n";
            cin >> x;
            system("pause");
            myList.addAtEnd(x);
            break;
        case 3:
            cout << "Danh sach:\n";
            myList.printList();
            system("pause");
            break;
        case 4:
            cout << "Them Node vao sau gia tri q:\n";
            cin >> x >> y;
            myList.addAfter(x,y);
            system("pause");
            break;
        case 5: 
            cout << "Them Node vao truoc gia tri q:\n";
            cin >> x >> y;
            myList.addBefore(x,y);
            system("pause");
            break;
        case 6:
            myList.removeFirst();
            system("pause");
            break;
        case 7:
            myList.removeLast();
            system("pause");
            break;
        case 8:
            cout << "Nhap gia tri q: ";
            cin >> x;
            myList.removeAfter(x);
            system("pause");
            break;
        case 9:
            cout << "Xoa Node co khoa k cach 1\n";
            cin >> x;
            myList.removeByKey1(x);
            system("pause");
            break;
        case 10:
            cout << "Xoa Node co khoa k cach 2\n";
            cin >> x;
            myList.removeByKey2(x);
            system("pause");
            break;
        case 11:
            cout << "Xoa Node tai vi tri n\n";
            cin >> x;
            myList.deleteNodeAtPosition(x);
            system("pause");
            break;
        case 12:
            cout << "Lay Node dau tien\n";
            myList.popFront();
            system("pause");
            break;
        case 13:
            cout << "Nhap danh sach Node\n";
            myList.inPutList();
            system("pause");
            break;
        case 14:
            cout << "Tim Node co gia tri k:\n";
            cin >> x;
            Node* temp;
            temp = myList.Search(x);
            if(temp != nullptr) cout << "Ton tai " << x << " trong danh sach!\n";
             else cout << x <<"Khong ton tai trong danh sach!\n";
            system("pause");
            break;
        case 15: 
            cout << "Dem cac phan tu theo do dai: ";
            x = myList.Length();
            cout << x << endl;
            system("pause");
            break;
        case 16: 
            cout << "Tim phan tu lon nhat:\n";
            myList.findMax();
            system("pause");
            break;
        case 17:
            cout << "Bubble Sort\n";
            myList.bubbleSort();
            system("pause");
            break;
        case 18: 
            cout << "Selection Sort\n";
            myList.selectionSort();
            system("pause");
            break;
        case 19:
            cout << "Insertion Sort\n";
            myList.insertionSort();
            system("pause");
            break;
        case 20:
            cout << "Nhap gia tri can them:\n";
            cin >> x;
            myList.addNodeSorted(x);
            myList.printList();
            system("pause");
            break;
        case 21:
            cout <<"Nhap dannh sach 2:\n";
            l2.inPutList();
            cout << "Noi 2 danh sach\n";
            myList.mergeSortedLists(l2);
            system("pause");
            break;
        case 22:
            cout << "In danh sach dao nguoc\n";
            myList.reverseList();
            myList.printList();
            system("pause");
            break;
        case 23:
            cout << "In danh sach dao nguoc bang de quy\n";
            myList.printReverseRecursive();
            system("pause");
            break;
        case 0:
            break;
        default:
            break;
        }
    }while(n!=0);
    
    myList.~LinkedList();
    l2.~LinkedList();
}
int main() {
    Menu();

    
    return 0;
}