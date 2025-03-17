#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct thietBi{
	char tenThietBi[50];
	int namSanXuat, gia;
}thietBi;


void nhap(int *n, thietBi *&a){
	printf("Nhap so luong thiet bi: ");
	scanf("%d", n);
	
    a = (thietBi*)malloc((*n)*sizeof(thietBi));
    
    for(int i=0; i < *n; i++){
    	printf("Nhap thong tin thiet bi thu %d:\n", i+1);
    	printf("Nhap ten: "); 
		scanf("%s", a[i].tenThietBi);
    	printf("Nhap nam san xuat: "); 
		scanf("%d", &a[i].namSanXuat);
    	printf("Nhap gia:"); 
		scanf("%d", &a[i].gia);
	}
}

void Xuat(int n, thietBi a[]) {
    printf("Danh sach cac thiet bi:\n");
    printf("%-30s  %-30s  %s\n", "Ten Thiet Bi", "Nam san xuat", "Gia");

    for (int i = 0; i < n; i++) {
        printf("%-30s  %d  %30d\n", a[i].tenThietBi, a[i].namSanXuat, a[i].gia);
    }
}

void vietDanhSachThietBiVaoTep(int n, thietBi a[]){
	FILE *fp;
	fp = fopen("danhsach.txt", "w");
	for(int i=0; i<n; i++){
		fprintf(fp, "%s %d %d\n", a[i].tenThietBi, a[i].namSanXuat, a[i].gia);
	}
	fclose(fp);
}

int demThietBi(int n, thietBi *a){
	int result, demThietBi = 0;
	char tenthietbi[50]; 
	printf("Nhap ten thiet bi can tim :");
	scanf("%s", tenthietbi);
	for (int i = 0; i < n; i++)
	{
		result = strcmp(tenthietbi, (a + i)->tenThietBi);
		if (result == 0)
		{
			demThietBi++;
		}
	}
	return demThietBi; 
}

// Sap xep thiet bi theo nam tang dan
void sapXepThietBiTheoNam(int n, thietBi a[]){
	for(int i=0; i<n-1; i++){
		int viTriNhoNhat = i;
		for(int j = i+1; j<n; j++){
			if(a[i].namSanXuat < a[j].namSanXuat){
				thietBi temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void timThietBi(int n, thietBi a[]){
	thietBi max = a[0];
	for(int i=1; i<n; i++){
		if(a[i].gia > max.gia) max = a[i];
	}
	printf("\nThiet bi %s co gia cao nhat la: %d", max.tenThietBi, max.gia);
}

int main(){
	int n;
	thietBi *a;
	nhap(&n, a);
	Xuat(n, a);
//	vietDanhSachThietBiVaoTep(n, a);
//    int x = demThietBi(n, a);
//    sapXepThietBiTheoNam(n, a);
//    Xuat(n, a);
    timThietBi(n, a);
}
