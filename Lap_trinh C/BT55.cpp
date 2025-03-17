#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tenSach[50];
    char tacGia[50];
    int namXuatBan;
} Sach;

void Nhap(int *n, Sach **A) {
    printf("Nhap so luong cuon sach: ");
    scanf("%d", n);

    *A = (Sach *)malloc((*n) * sizeof(Sach));

    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin cuon sach thu %d:\n", i + 1);
        printf("Ten sach: ");
        getchar();
        fgets((*A)[i].tenSach, 50, stdin);
        printf("Tac gia: ");
        fgets((*A)[i].tacGia, 50, stdin);
        printf("Nam xuat ban: ");
        scanf("%d", &(*A)[i].namXuatBan);
    }
}

void Xuat(int n, Sach A[]) {
    for (int i = 0; i < n; i++) {
        printf("Thong tin cuon sach thu %d:\n", i + 1);
        printf("Ten sach: %s", A[i].tenSach);
        printf("Tac gia: %s", A[i].tacGia);
        printf("Nam xuat ban: %d\n", A[i].namXuatBan);
    }
}

int DemSach(int n, Sach *A) {
    char tacGia[50];
    int dem = 0;

    printf("Nhap ten tac gia can dem: ");
    getchar();
    fgets(tacGia, 50, stdin);

    for (int i = 0; i < n; i++) {
        if (strcmp(A[i].tacGia, tacGia) == 0) {
            dem++;
        }
    }

    return dem;
}

void ThongKe(int n, Sach *A) {
    int nam[100] = {0};

    for (int i = 0; i < n; i++) {
        nam[A[i].namXuatBan]++;
    }

    for (int i = 0; i < 100; i++) {
        if (nam[i] > 0) {
            printf("%d : %d cuon\n", i, nam[i]);
        }
    }
}

int Menu() {
    int choice;

    printf("\n--- MENU ---\n");
    printf("1. Nhap n cuon sach\n");
    printf("2. Xuat n cuon sach\n");
    printf("3. Dem theo tac gia\n");
    printf("4. Thong ke\n");
    printf("5. Thoat\n");
    printf("Lua chon: ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    int n;
    Sach *A = NULL;
    int choice;

    do {
        choice = Menu();

        switch (choice) {
            case 1:
                Nhap(&n, &A);
                break;
            case 2:
                Xuat(n, A);
                break;
            case 3: {
                int dem = DemSach(n, A);
                printf("So cuon sach cua tac gia: %d\n", dem);
                break;
            }
            case 4:
                ThongKe(n, A);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 5);

    if (A != NULL) {
        free(A);
    }

    return 0;
}
