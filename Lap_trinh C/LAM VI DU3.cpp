#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ð?nh nghia c?u trúc c?a m?t nút trong danh sách liên k?t don
typedef struct Node {
    int coefficient;  // H? s?
    int exponent;    // Luy th?a
    struct Node* next;  // Con tr? tr? d?n nút ti?p theo trong danh sách
} Node;

// Hàm t?o m?t nút m?i v?i h? s? và luy th?a cho tru?c
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Hàm chèn m?t nút m?i vào d?u danh sách
void insertNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

// Hàm tính giá tr? c?a da th?c t?i m?t giá tr? x
int calculatePolynomial(Node* head, int x) {
    int result = 0;
    Node* current = head;

    while (current != NULL) {
        result += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }

    return result;
}

// Hàm hi?n th? danh sách liên k?t don
void displayList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("(%d, %d) ", current->coefficient, current->exponent);
        current = current->next;
    }

    printf("\n");
}

// Hàm gi?i phóng b? nh? c?a danh sách liên k?t don
void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    Node* polynomial = NULL;
    int coefficient, exponent;
    int x, result;

    // Nh?p h? s? và luy th?a c?a da th?c
    printf("Nhap he so va luy thua cua da thuc (nhap -1 -1 de ket thuc):\n");
    do {
        printf("Nhap he so: ");
        scanf("%d", &coefficient);
        printf("Nhap luy thua: ");
        scanf("%d", &exponent);

        if (coefficient != -1 && exponent != -1) {
            Node* newNode = createNode(coefficient, exponent);
            insertNode(&polynomial, newNode);
        }
    } while (coefficient != -1 && exponent != -1);

    // Hi?n th? danh sách da th?c
    printf("Danh sach da thuc: ");
    displayList(polynomial);
    
    freeList(&polynomial);
    return 0;
    
}

