#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

class BST{
    private:
        Node* root;
        int n;//Số lượng Node
        int Pre, Post, In;
    public:
        BST() {n = Pre = Post = In = 0;root = nullptr;}
        ~BST(){
            destroyTree(root);
        }
        int getPre(){
            return Pre;
        }

        // Hàm giải phóng bộ nhớ của cây
        void destroyTree(Node* root) {
            if (root != nullptr) {
                destroyTree(root->left);
                destroyTree(root->right);
                delete root;
            }
        }
        Node* &getRoot(){return root;}
        int getN(){return n;}

        void insertRec(Node* &root, int value); //Chèn một giá trị vào cây
        Node* searchRec(Node* head,int x); // Tìm kiếm giá trị(đệ quy)
        Node* search(int x); //Tìm kiếm giá trị(không dùng đệ quy)
        void removeRec(Node* &root, int x);//Xóa giá trị
        Node* searchRecMax(Node* root);//Tìm giá trị lớn nhất
        Node* searchRecMin(Node* root);//Tìm giá trị nhỏ nhất
        int Height(Node* head);//Tìm chiều cao(Mức lớn nhất)
        int sumNegativeValue(Node* head);//Tính tổng các giá trị âm
        int productPositiveValue(Node* head);//Tính tích các giá trị dương 
        bool isAllNegative(Node* node);//Kiểm tra cây toàn số âm
        int productPositiveValueHelper(Node* head);//Đệ quy tính tích các số dương
        bool isExistsValue0();//Kiểm tra trong cây có tồn tại giá trị 0 hay không
        void preOrder(Node* head);//Duyệt trước
        void inOrder(Node* head);//Duyệt giữa
        void postOrder(Node* head);//Duyệt sau
        void printNodeLessX(Node* head, int x, bool &check);//In ra các Node có giá trị nhỏ hơn x
        void printNodeInRange(Node* head, int x, int y, bool &check);//In ra các Node có giá trị lớn hơn x và nhỏ hơn y
        void printPerfectNumber(Node* head, bool &check);//In ra các Node hoàn hảo
        int calLevelNode(Node* head, int x);//Tìm mức của một Node có giá trị x
        void printNodeAtLevel(int k, bool &check);//In các Node ở tầng k
        void printNodeLevel(Node* head);//In các Node theo tầng 
        int coutNodeOneChild(Node* head);//Đếm Node có 1 con
        int coutNodeTwoChild(Node* head);//Đếm Node có 2 con
        int coutEventNode(Node* head);//Đếm Node chẵn
        int coutNodeLeafEvent(Node* head);//Đếm Node lá chẵn
        int coutNodeOneChildPrime(Node* head);//Đếm Node có 1 con và là số nguyên tố
        int coutNodeTwoChildSquare(Node* head);//Đếm Node có 2 con và là số chính phương
        int coutAllNode(){return n;}//Đếm các Node
        int coutNodeLeaf(Node* head);//Đếm Node lá
        int coutBranchNode(Node* head);//Đếm Node nhánh       
        int coutNegativeNode(Node* head);//Đếm Node âm
        int coutNodeAtK(Node* head, int k, int current);//Đếm Node trên tầng thứ k
        int coutNodeLowerK(Node* head, int k, int current);//Đếm số Node ở tầng thấp hơn k
        int coutNodeHigherK(Node* head, int k, int current);//Đếm số Node ở tầng cao hơn k
        int coutNodeGreaterK(Node* head, int k);//Đếm Node có giá trị lớn hơn k
};


//Chèn giá trị vào cây
void BST::insertRec(Node* &head, int value){
    if(head == nullptr){
        head =  new Node(value);
        n++;
    }
    else {
        if(value < head->data  ){
            insertRec(head->left, value);
        }
        else if(value > head->data){
            insertRec(head->right, value);
        }
    }
}

//Tìm node có khóa bằng x(dùng đệ quy)
Node* BST::searchRec(Node* head, int x){
    if(head == nullptr || head->data == x) return head;

    if(x < head->data) return searchRec(head->left, x);
    else return searchRec(head->right, x);
}

//Tìm node có khóa bằng x (không dùng đệ quy)
Node* BST::search(int x) {
    Node* current = root;
    while (current != nullptr && current->data != x) {
        if (x < current->data) {
            current = current->left;
            Pre++;
        } else {
            current = current->right;
            Pre++;
        }
    }
    return current;
}

//Xóa Node 
void BST::removeRec(Node* &head, int x){
    if(head == nullptr) return ;

    if(x < head->data){
        removeRec(head->left, x);
    }
    else if(x > head->data){
        removeRec(head->right, x);
    }
    else{
        if(head->left == nullptr){
            Node* temp = head->right;
            delete head;
            n--;
            head = temp;
        }
        else if(head->right == nullptr){
            Node* temp = head->left;
            delete head;
            n--;
            head = temp;
        }
        else{
            Node* temp = searchRecMin(head->right);
            head->data = temp->data;
            removeRec(head->right, temp->data);
        }
    }
}

//Tìm Node có giá trị max
Node* BST::searchRecMax(Node* head){
    if(head == nullptr) return head;
    while (head->right != nullptr)
    {
        head = head->right;
    }
    return head;
}

//Tìm Node có giá trị min
Node* BST::searchRecMin(Node* head){
    if(head == nullptr) return head;
    while (head->left != nullptr)
    {
        head = head->left;
    }
    
    return head;
}

//Tìm chiều cao của cây
int BST::Height(Node* head){
    if(head == nullptr) return 0;

    int left = Height(head->left);
    int right = Height(head->right);

    return 1 + max(left, right);
    
}

//Tính tổng giá trị âm
int BST::sumNegativeValue(Node* head){
    if(head == nullptr) return 0;

    int sum = 0;
    if(head->data < 0) sum += head->data;

    sum += sumNegativeValue(head->left);
    sum += sumNegativeValue(head->right);

    return sum;
}

//Kiểm tra cây toàn số âm
bool BST::isAllNegative(Node* node) {
    if (node == nullptr) {
        return true;
    }

    return (node->data <= 0) && isAllNegative(node->left) && isAllNegative(node->right);
}

//Hàm tính tích các số dương
int BST::productPositiveValueHelper(Node* head) {
    if (head == nullptr)
        return 1;

    int leftProduct = productPositiveValueHelper(head->left);
    int rightProduct = productPositiveValueHelper(head->right);

    if (head->data > 0) {
        return head->data * leftProduct * rightProduct;
    } else {
        return max(leftProduct, rightProduct);
    }
}

//Kiểm tra điều kiện và xuất ra tích 
int BST::productPositiveValue(Node* head) {
    if (isAllNegative(head)) {
        return 0; // Trả về 0 nếu cây toàn số âm
    }
    return productPositiveValueHelper(head);
}

//Kiểm tra trong cây có tồn tại giá trị 0 
bool BST::isExistsValue0(){
    Node* res = search(0);

    return res == nullptr ? false : true;
}

//Duyệt trước
void BST::preOrder(Node* head){
    if(head == nullptr) return;

    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

//Duyệt giữa
void BST::inOrder(Node* head){
    if(head == nullptr) return;

    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

//Duyệt sau
void BST::postOrder(Node* head){
    if(head == nullptr) return;

    postOrder(head->left);
    postOrder(head->right);
    cout << head->data << " ";
}

//In ra các Node có giá trị nhỏ hơn x
void BST::printNodeLessX(Node* head, int x, bool &check){
    if(head == nullptr) return;

    if(head->data < x){
        cout << head->data << " ";
        check = true;
    } 

    printNodeLessX(head->left, x, check);
    printNodeLessX(head->right, x, check);
}

//In ra các Node có giá trị nhỏ hơn y và lớn hơn x
void BST::printNodeInRange(Node* head, int x, int y, bool &check){
    if(head == nullptr) return;

    if(head->data > x && head->data < y){
        cout << head->data << " "; 
        check = true;
    } 
    printNodeInRange(head->left, x, y, check);
    printNodeInRange(head->right, x, y, check);
}

// Hàm kiểm tra xem một số có phải là số hoàn hiện hay không
bool isPerfectNumber(int num) {
    int sum = 1; // Tổng của ước số 1 (chính nó)
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }
    return sum == num;
}

//In ra các số hoàn thiện trong cây
void BST::printPerfectNumber(Node* head, bool &check){
    if(head == nullptr) return;

    if(isPerfectNumber(head->data)){
        cout << head->data << " ";
        check = true;
    }

    printPerfectNumber(head->left, check);
    printPerfectNumber(head->right, check);
}

//Tính mức của Node có giá trị x
int BST::calLevelNode(Node* head, int x){
    if(head == nullptr) return -1;

    int level = 0;
    while (head != nullptr)
    {
        if(head->data == x) return level;
        else if(x < head->data) head = head->left;
        else head = head->right;

        level ++;
    }

    return -1;
    
}

// Hàm đệ quy xuất các nút trên tầng thứ k của cây
void printNodesAtLevelKRecursive(Node* node, int k, int currentLevel, bool &check) {
    if (node == nullptr) {
        return;
    }

    // Nếu đến tầng k, in ra giá trị của nút
    if (currentLevel == k) {
        cout << node->data << " ";
        check = true;
    }

    currentLevel++;
    // Duyệt đệ quy vào cây con bên trái và bên phải
    printNodesAtLevelKRecursive(node->left, k, currentLevel, check);
    printNodesAtLevelKRecursive(node->right, k, currentLevel, check);
}

//In ra các Node ở tầng k
void BST::printNodeAtLevel(int k, bool &check){
    printNodesAtLevelKRecursive(root, k, 0, check);
}

//In các Node theo tầng
void BST::printNodeLevel(Node* head){
    if(head == nullptr) return;

    bool check = false;
    int n = Height(head);
    for(int i=0; i<n; i++){
        printNodeAtLevel(i, check);
        if(check) cout << "(Tang " << i << ")\n";
        else cout << "KTT Node o tang " << i << endl;
    }
    
}

//Đếm Node có 1 con
int BST::coutNodeOneChild(Node* head){
    if(head == nullptr) return 0;

    int left = coutNodeOneChild(head->left);
    int right = coutNodeOneChild(head->right);

    if((head->left == nullptr && head->right != nullptr) || (head->left != nullptr && head->right == nullptr))
        return 1 + left + right;
    else return left + right;
}

//Đếm Node có 2 con
int BST::coutNodeTwoChild(Node* head){
    if(head == nullptr) return 0;

    int left = coutNodeTwoChild(head->left);
    int right = coutNodeTwoChild(head->right);

    if( head->right != nullptr && head->left != nullptr)
        return 1 + left + right;
    else return left + right;

}

//Đếm Node chẵn
int BST::coutEventNode(Node* head){
    if(head == nullptr) return 0;

    int left = coutEventNode(head->left);
    int right = coutEventNode(head->right);

    if(head->data % 2 == 0)
        return 1 + left + right;
    else return left + right;
}

//Đếm Node lá chẵn
int BST::coutNodeLeafEvent(Node* head){
    if(head == nullptr) return 0;

    int left = coutNodeLeafEvent(head->left);
    int right = coutNodeLeafEvent(head->right);

    if(head->left == nullptr && head->right == nullptr && head->data % 2 == 0 )
        return 1 + left + right;
    else return left + right;
}

// kiểm tra số nguyên tố
bool isPrime(int n) {
    // Số nguyên tố là số nguyên dương lớn hơn 1 không chia hết cho số nào ngoại trừ 1 và chính nó.
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

//Đếm Node có 1 con và là số nguyên tố
int BST::coutNodeOneChildPrime(Node* head){
    if(head == nullptr) return 0;

    int left = coutNodeTwoChild(head->left);
    int right = coutNodeTwoChild(head->right);

    if( (head->right != nullptr && head->left == nullptr) || (head->left!= nullptr && head->right == nullptr) && isPrime(head->data))
        return 1 + left + right;
    else return left + right;
}

//Kiểm tra số chính phương
bool isPerfectSquare(int n) {
    int sqrtN = sqrt(n);
    return (sqrtN * sqrtN == n);
}

//Đêm Node có 2 con và là số chính phương
int BST::coutNodeTwoChildSquare(Node* head){
   if(head == nullptr) return 0;

    int left = coutNodeTwoChildSquare(head->left);
    int right = coutNodeTwoChildSquare(head->right);

    if( (head->right != nullptr && head->left != nullptr) && isPerfectSquare(head->data))
        return 1 + left + right;
    else return left + right; 
}

//Đếm Node lá
int BST::coutNodeLeaf(Node* head){
    if(head == nullptr) return 0;

    int left = coutNodeLeaf(head->left);
    int right = coutNodeLeaf(head->right);

    if(head->left == nullptr && head->right == nullptr)
        return 1 + left + right;
    else return left + right;
}

//Đếm Node nhánh
int BST::coutBranchNode(Node* head){
    if (head == nullptr) {
        return 0;
    }

    if (head->left != nullptr || head->right != nullptr) {
        return 1 + coutBranchNode(head->left) + coutBranchNode(head->right);
    } else {
        return 0;
    }

}

//Đếm Node âm
int BST::coutNegativeNode(Node* head){
    if(head == nullptr) return 0;
    
    int count = (head->data < 0) ? 1 : 0;
    count += coutNegativeNode(head->left);
    count += coutNegativeNode(head->right);
    return count;
}

//Đếm Node trên tầng thứ k
int BST::coutNodeAtK(Node* head, int k, int current){
    if (head == nullptr) {
        return 0;
    }
    
    if (current == k) {
        return 1;
    }

    current++;
    // Duyệt đệ quy vào cây con bên trái và bên phải
    return coutNodeAtK(head->left, k, current) +
           coutNodeAtK(head->right, k, current);
}

//Đếm số Node ở tầng thấp hơn tầng k
int BST::coutNodeLowerK(Node* head, int k, int current){
    if (head == nullptr) {
        return 0;
    }
    
    if (current > k) {
        return 1;
    }

    current++;
    // Duyệt đệ quy vào cây con bên trái và bên phải
    return coutNodeLowerK(head->left, k, current) +
           coutNodeLowerK(head->right, k, current);
}

//Đếm số Node ở tầng cao hơn k
int BST::coutNodeHigherK(Node* head, int k, int current){
    if (head == nullptr) return 0;
    
   if(current == k) return 0;

    current++;
    // Duyệt đệ quy vào cây con bên trái và bên phải
    return 1 + coutNodeHigherK(head->left, k, current ) +
           coutNodeHigherK(head->right, k, current );
}

//Đếm Node có giá trị lớn hơn k
int BST::coutNodeGreaterK(Node* head, int k){
    if(head == nullptr) return 0;

    int count = (head->data > k) ? 1 : 0;

    count += coutNodeGreaterK(head->left, k);
    count += coutNodeGreaterK(head->right, k);
    return count;
}

int main(){
    BST myBST;
    Node* &root = myBST.getRoot();
    int n, x;
    Node* res;
    bool temp = false;

    do{
    system("cls");
    cout << "\n	        \t\tMENU           ";
    cout << "\n	+----------------------------------------------------------------------------------------------+";
    cout << "\n	| [1]. Chen Node vao cay                  | [6]. Tim Node nho nhat                             |";
    cout << "\n	| [2]. Tim Node(de quy)                   | [7]. Tinh chieu cao cay                            |";
    cout << "\n	| [3]. Tim Node(khong de quy)             | [8]. Tong cac Node am                              |";
    cout << "\n	| [4]. Xoa Node                           | [9]. Tich cac Node duong                           |";
    cout << "\n	| [5]. Tim Node lon nhat                  | [10].  Kiem tra cay co chua Node 0                 |";
    cout << "\n	| [11]. Duyet truoc(Pre-Order)            | [23]. Dem Node la chan                             |";
    cout << "\n	| [12]. Duyet giua(In-Order)              | [24]. Dem Node co 1 con va la so nguyen to         |";
    cout << "\n	| [13]. Duyet sau(Post-Order)             | [25]. Dem Node co dung 2 con va la so chinh phuong |";
    cout << "\n	| [14]. In ra cac Node co gia tri < x     | [26]. Dem tat ca cac Node                          |";
    cout << "\n	| [15]. In ra cac Node co x < gia tri < y | [27]. Dem tat ca Node la                           |";
    cout << "\n	| [16]. In cac so hoan thien              | [28]. Dem tat ca Node nhanh                        |";
    cout << "\n	| [17]. Tinh muc(level) cua Node          | [29]. Dem Node am                                  |";
    cout << "\n	| [18]. Xuat Node tren tang k             | [30]. Dem Node tren tang k                         |";
    cout << "\n	| [19]. Xuat Node tu tang 0 -> (h-1)      | [31]. Dem Node o tang thap hon k                   |";
    cout << "\n	| [20]. Dem Node co dung 1 con            | [32]. Dem Node o tang cao hon k                    |";
    cout << "\n	| [21]. Dem Node co dung 2 con            | [33]. Dem Node lon hon x                           |";
    cout << "\n	| [22]. Dem Node chan                     | [34]. Xoa toan bo cay                              |";
    cout << "\n	| [0]. Thoat                              |                                                    |";
    cout << "\n	+----------------------------------------------------------------------------------------------+\n";
    

    

        cout << "Chon: ";
        cin >> n;
        switch(n){
            case 1:
                cout << "Nhap gia tri them: ";
                cin >> x;
                myBST.insertRec(root, x);
                system("pause");
                break;
            case 2:
                cout << "Nhap Node can tim: ";
                cin >> x;
                res = myBST.search(x);
                if(res == nullptr) cout << "Khong tim thay Node co gia tri " << x << endl;
                else cout << "Ton tai Node co gia tri " << x << endl;
                system("pause");
                break;
            case 3:
                cout << "Nhap Node can tim: ";
                cin >> x;
                res = myBST.searchRec(root, x);
                if(res == nullptr) cout << "Khong tim thay Node co gia tri " << x << endl;
                else cout << "Ton tai Node co gia tri " << x << endl;
                system("pause");
                break;
            case 4:
                cout << "Nhap Node can xoa: ";
                cin >> x;
                myBST.removeRec(root, x);
                system("pause");
                break;
            case 5:
                res = myBST.searchRecMax(root);
                if(res == nullptr) cout << "Cay rong!\n";
                else cout << "Node co gia tri lon nhat " << res->data << endl;
                system("pause");
                break;
            case 6:
                res = myBST.searchRecMin(root);
                if(res == nullptr) cout << "Cay rong!\n";
                else cout << "Node co gia tri nho nhat " << res->data << endl;
                system("pause");
                break;
            case 7:
                x = myBST.Height(root);
                if(x == 0) cout << "Cay rong!\n";
                else cout << "Chieu cao cua cay " << x << endl;
                system("pause");
                break;
            case 8:
                x = myBST.sumNegativeValue(root);
                if(x == 0) cout << "Cay khong co so am hoac cay rong!\n";
                else cout << "Tong gia tri am tren cay " << x << endl;
                system("pause");
                break; 
            case 9:
                x = myBST.productPositiveValue(root);
                if(x == 0) cout << "Cay khong co so duong hoac cay rong!\n";
                else cout << "Tich gia tri duong tren cay " << x << endl;
                system("pause");
                break; 
            case 10:
                temp = myBST.isExistsValue0();
                if(!temp) cout << "Cay khong ton tai 0 hoac rong!\n";
                else cout << "Ton tai gia tri 0\n";
                system("pause");
                break;
            case 11:
                cout << "Danh sach cay: ";
                myBST.preOrder(root);
                cout << endl;
                system("pause");
                break;
            case 12:
                cout << "Danh sach cay: ";
                myBST.inOrder(root);
                cout << endl;
                system("pause");
                break;
            case 13:
                cout << "Danh sach cay: ";
                myBST.postOrder(root);
                cout << endl;
                system("pause");
                break;
            case 14:
                cout << "Nhap x: ";
                cin >> x;
                myBST.printNodeLessX(root, x, temp);
                if(!temp) {
                    cout << "Khong co gia tri nho hon " << x << " hoac cay rong!\n";
                    system("pause");
                    break;
                }
                cout << endl;
                system("pause");
                break;
            case 15:
                cout << "Nhap x: "; cin >> x;
                cout << "Nhap y: "; cin >> n;
                myBST.printNodeInRange(root, x, n, temp);
                if(!temp) {
                    cout << "Khong co " << x << "< gia tri < " << n  <<  " hoac cay rong!\n";
                    system("pause");
                    break;
                }
                cout << endl;
                system("pause");
                break;
            case 16:
                myBST.printPerfectNumber(root, temp);
                if(!temp) {
                    cout << "Cay khong co so hoan thien hoac cay rong!\n";
                    system("pause");
                    break;
                }
                cout << endl;
                system("pause");
                break;
            case 17:
                cout << "Nhap node: "; cin >> x;
                n = myBST.calLevelNode(root, x);
                if(n == -1) cout << "Khong ton tai " << x << " trong cay!\n";
                else cout << "Muc cua Node " << x << " la " << n << endl;
                system("pause");
                break; 
            case 18:
                cout << "Nhap tang k: "; cin >> x;
                myBST.printNodeAtLevel(x, temp);
                if(!temp) {
                    cout << "Khong ton tai Node o tang k hoac cay rong!\n";
                    system("pause");
                    break;
                }
                cout << endl;
                system("pause");
                break;
            case 19:
                myBST.printNodeLevel(root);
                system("pause");
                break;
            case 20:
                x = myBST.coutNodeOneChild(root);
                if(x == 0) cout << "Cay khong co Node co dung 1 con\n";
                else cout << "So Node co dung 1 con cua cay: " << x << endl;
                system("pause");
                break;
            case 21:
                x = myBST.coutNodeTwoChild(root);
                if(x == 0) cout << "Cay khong co Node co dung 2 con\n";
                else cout << "So Node co dung 2 con cua cay: " << x << endl;
                system("pause");
                break;
            case 22:
                x = myBST.coutEventNode(root);
                if(x == 0) cout << "Cay khong co Node chan\n";
                else cout << "So Node chan cua cay: " << x << endl;
                system("pause");
                break;
            case 23:
                x = myBST.coutNodeLeafEvent(root);
                if(x == 0) cout << "Cay khong co Node la chan\n";
                else cout << "So Node la chan cua cay: " << x << endl;
                system("pause");
                break;
            case 24:
                x = myBST.coutNodeOneChildPrime(root);
                if(x == 0) cout << "Cay khong co Node co dung 1 con va la so nguyen to\n";
                else cout << "So Node co dung 1 con va la so nguyen to cua cay: " << x << endl;
                system("pause");
                break;
            case 25:
                x = myBST.coutNodeTwoChildSquare(root);
                if(x == 0) cout << "Cay khong co Node co dung 2 con va la so chinh phuong\n";
                else cout << "So Node co dung 2 con va la so chinh phuong cua cay: " << x << endl;
                system("pause");
                break;
            case 26:
                x = myBST.coutAllNode();
                if(x == 0) cout << "Cay rong\n";
                else cout << "So Node cua cay: " << x << endl;
                system("pause");
                break;
            case 27:
                x = myBST.coutNodeLeaf(root);
                if(x == 0) cout << "Cay khong co Node la\n";
                else cout << "So Node la cua cay: " << x << endl;
                system("pause");
                break;
            case 28:
                x = myBST.coutBranchNode(root);
                if(x == 0) cout << "Cay khong co Node nhanh\n";
                else cout << "So Node nhanh cua cay: " << x << endl;
                system("pause");
                break;
            case 29:
                x = myBST.coutNegativeNode(root);
                if(x == 0) cout << "Cay khong co Node am\n";
                else cout << "So Node am cua cay: " << x << endl;
                system("pause");
                break;
            case 30:
                cout << "Nhap tang k: ";
                cin >> n;
                x = myBST.coutNodeAtK(root, n, 0);
                if(x == 0) cout << "Cay khong co Node o tang thu " << n << endl;
                else cout << "So Node o tang thu " << n << " cua cay: " << x << endl;
                system("pause");
                break;
            case 31:
                cout << "Nhap tang k: ";
                cin >> n;
                x = myBST.coutNodeLowerK(root, n, 0);
                if(x == 0) cout << "Cay khong co Node o tang thap tang thu " << n << endl;
                else cout << "So Node o tang thap hon tang thu " << n << " cua cay: " << x << endl;
                system("pause");
                break;
            case 32:
                cout << "Nhap tang k: ";
                cin >> n;
                x = myBST.coutNodeHigherK(root, n, 0);
                if(x == 0) cout << "Cay khong co Node o tang cao hon tang thu " << n << endl;
                else cout << "So Node o tang cao hon tang thu " << n << " cua cay: " << x << endl;
                system("pause");
                break;
            case 33:
                cout << "Nhap x: ";
                cin >> n;
                x = myBST.coutNodeGreaterK(root, n);
                if(x == 0) cout << "Cay khong co Node co gia tri lon hon " << n << endl;
                else cout << "So Node co gia tri lon hon " << n << " cua cay: " << x << endl;
                system("pause");
                break;
            case 34:
                myBST.~BST();
                system("pause");
                break;
            case 35:
                cout << myBST.getPre();
                system("pause");
                break;
            case 0:
                break;
            default:
                cout << "Khong co chuc nang trong MENU!\n Moi nhap lai!\n";
                system("pause");
                break;
        } 
    }while (n!=0);
    

    myBST.~BST();
    return 0;
}