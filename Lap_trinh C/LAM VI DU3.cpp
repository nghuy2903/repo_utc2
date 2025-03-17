#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �?nh nghia c?u tr�c c?a m?t n�t trong danh s�ch li�n k?t don
typedef struct Node {
    int coefficient;  // H? s?
    int exponent;    // Luy th?a
    struct Node* next;  // Con tr? tr? d?n n�t ti?p theo trong danh s�ch
} Node;

// H�m t?o m?t n�t m?i v?i h? s? v� luy th?a cho tru?c
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// H�m ch�n m?t n�t m?i v�o d?u danh s�ch
void insertNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

// H�m t�nh gi� tr? c?a da th?c t?i m?t gi� tr? x
int calculatePolynomial(Node* head, int x) {
    int result = 0;
    Node* current = head;

    while (current != NULL) {
        result += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }

    return result;
}

// H�m hi?n th? danh s�ch li�n k?t don
void displayList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("(%d, %d) ", current->coefficient, current->exponent);
        current = current->next;
    }

    printf("\n");
}

// H�m gi?i ph�ng b? nh? c?a danh s�ch li�n k?t don
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

    // Nh?p h? s? v� luy th?a c?a da th?c
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

    // Hi?n th? danh s�ch da th?c
    printf("Danh sach da thuc: ");
    displayList(polynomial);
    
    freeList(&polynomial);
    return 0;
    
}

