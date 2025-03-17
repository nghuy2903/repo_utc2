/*
Hà Văn Dũng - Nguyễn Nguyên Huy
*/

#include <bits/stdc++.h>
using namespace std;


class node
{
    public: 
      int data;
      node* left;
      node* right;
      node(int value);
};

node::node(int value)
{
    data = value;
    left = nullptr;
    right = nullptr;
}

class BST
{
public:
    BST();
    node *root;
    bool isEmpty(node *root);// Kiem tra rong
    void insert(node *&, int value); // Them Node
    node *FindMax(node *root); 
    node *remove(node *&, int value); // Xoa nut bat ky
    void clear(node *&);

    void printAscending(node *root);
    void printDescending(node *root);

    bool isProperBT(node *root);

    int countNodes(node *root);
    bool isFullBinaryTree(node *root, int index, int nodeCount);
    bool isFullBinaryTree(node *root);

    node *searchNode(node *root, int value );
    node *findParent(node *root, node *node);
    node *findParentOfNode(node *root, int value );

    int countLeafNodes(node *root);
    int countInternalNodes(node *root);
    int calculateSize(node *root);

    int calculateHeight(node *root);

    int findMinValue(node *root);
    int findMaxValue(node *root);

    int calculateSum(node *root);
};

BST::BST()
{
    root = NULL;
}

bool BST::isEmpty(node* root)
{
    return root == nullptr ? true : false;
}

void BST::insert(node* &root, int value)
{
    if(root == nullptr) root = new node(value);
    else
    {
        if(value > root->data) insert(root->right, value);
        else if(value < root->data) insert(root->left, value);
    }
}

node* BST::FindMax(node *root)
{
    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}

// node *BST::remove(node *&root, int key)
// {
//     if (root == NULL)
//         return root;
//     else if (key < root->data)
//         root->left = remove(root->left, key);
//     else if (key > root->data)
//         root->right = remove(root->right, key);
//     else
//     {
//         /* Case 1:  Node lá, không có con */
//         if (root->left == NULL && root->right == NULL)
//         {
//             delete root;
//             root = NULL;
//         }
//         /* Case 2: Có một con  */
//         else if (root->left == NULL)
//         {
//             node *temp = root;
//             root = root->right;
//             delete temp;
//         }
//         else if (root->right == NULL)
//         {
//             node *temp = root;
//             root = root->left;
//             delete temp;
//         }
//         /* case 3: Có hai con */
//         else
//         {
//             node *temp = FindMax(root->left);
//             root->data = temp->data;
//             root->left = remove(root->left, temp->data);
//         }
//     }
//     return root;
// }

node *BST::remove(node *&root, int key) {
    if (root == nullptr) {
        return root; // Trường hợp cơ bản: Nếu cây rỗng hoặc nút gốc chứa giá trị cần xóa, ta xử lý xóa nút này.
    }

    if (key < root->data) {
        root->left = remove(root->left, key); // Di chuyển đến cây con bên trái.
    } else if (key > root->data) {
        root->right = remove(root->right, key); // Di chuyển đến cây con bên phải.
    } else {
        // Nếu nút cần xóa có giá trị bằng với nút gốc, thực hiện việc xóa nút này.
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp; // Trường hợp 1: Nút có ít hơn hoặc bằng 1 con.
        } else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp; // Trường hợp 2: Nút có ít hơn hoặc bằng 1 con.
        } else {
            // Trường hợp 3: Nút có 2 con.
            // Tìm phần tử thay thế lớn nhất trong cây con bên trái (hoặc nhỏ nhất trong cây con bên phải).
            node* temp = FindMax(root->left); // Chọn phần tử lớn nhất trong cây con bên trái.
            root->data = temp->data; // Copy giá trị của phần tử thay thế vào nút gốc.
            root->left = remove(root->left, temp->data); // Xóa phần tử thay thế từ cây con bên trái.
        }
    }
    return root;
}
/*
Điều kiện dừng (base case):

Hàm đệ quy bắt đầu với việc kiểm tra nếu cây đang xét (root) là rỗng hoặc nút gốc của cây này có giá trị bằng với key cần xóa. Trong cả hai trường hợp này, không cần thực hiện xóa, và ta trả về con trỏ hiện tại (root) như vậy cây không bị thay đổi.
Di chuyển qua cây con phù hợp:

Nếu key nhỏ hơn giá trị của nút gốc (key < root->data), ta di chuyển đến cây con bên trái và gọi lại hàm remove trên cây con bên trái (root->left).
Nếu key lớn hơn giá trị của nút gốc (key > root->data), ta di chuyển đến cây con bên phải và gọi lại hàm remove trên cây con bên phải (root->right).
Trường hợp tìm thấy nút cần xóa (key == root->data):

Trường hợp 1: Nếu nút cần xóa là nút lá (nút không có con), ta xóa nút này bằng cách giải phóng bộ nhớ và trả về nullptr hoặc con trái (nếu nút cha đã trỏ đến nút này) hoặc con phải (nếu nút cha trỏ đến nút khác).
Trường hợp 2: Nếu nút cần xóa có một con, ta xóa nút này và trả về con đó, để nút cha trỏ đến con đó thay vì nút cần xóa.
Trường hợp 3: Nếu nút cần xóa có hai con, ta phải tìm một nút thay thế, thường là nút lớn nhất trong cây con bên trái (hoặc nhỏ nhất trong cây con bên phải). Chúng ta copy giá trị của nút thay thế vào nút cần xóa, sau đó xóa nút thay thế khỏi cây (sử dụng đệ quy).
Tổng cộng, thuật toán remove này sử dụng đệ quy để tìm và xóa nút cần loại bỏ khỏi cây BST, đồng thời đảm bảo tính nhất quán của cây sau mỗi lần xóa.
*/

void BST::printAscending(node* root)
{
   if(root == nullptr) return;

   printAscending(root->left);

   cout << root->data << " ";

   printAscending(root->right);

}

void BST::printDescending(node* root)
{
    if(root == nullptr) return;

   printDescending(root->right);

   cout << root->data << " ";

   printDescending(root->left);

}


int main()
{
    BST bst;

    bst.insert(bst.root, 5);
    bst.insert(bst.root, 2);
    bst.insert(bst.root, 6);
    bst.insert(bst.root, 3);

    bst.remove(bst.root, 6);
    
    bst.printDescending(bst.root);

    return 0;
}