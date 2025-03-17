#include <stdio.h>
#include <stdlib.h>

//TAO DU LIEU THIET BI
typedef struct{
	char tenThietBi[50];
	int namSanXuat, gia;
}thietBi;


// HAM NHAP
void nhapThietBi(thietBi *&a, int &n){
	printf("Nhap so luong thiet bi: "); scanf("%d", &n);
	a = (thietBi*)malloc((n) * sizeof(thietBi));
	for(int i=0; i<n; i++){
		printf("Nhap thong tin thiet bi thu %d\n", i+1);
		printf("Ten: "); scanf("%s", a[i].tenThietBi);
		printf("Nam san suat: "); scanf("%d", &a[i].namSanXuat);
		printf("Nhap gia: "); scanf("%d", &a[i].gia);
	}
}

// HAM XUAT
void xuatThietBi(thietBi a[], int n){
	for(int i=0; i<n; i++){
		printf("Thong tin thiet bi thu %d: ten: %s - namSanXuat: %d - Gia: %d\n", (i+1), a[i].tenThietBi, a[i].namSanXuat, a[i].gia);
	}
	printf("\n");
}

void sapXepTheoGia(thietBi a[], int n){
	for(int i=0; i<n-1; i++){		
		thietBi giaCao = a[i];
		for(int j=i+1; j<n; j++){
			if(a[j].gia > giaCao.gia){
				thietBi temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			} 
		}		
	}
	
}

void demThietBiTheoGia(thietBi a[], int n, int giaDem){
	printf("\nCac thiet bi cung gia:\n");
	for(int i=0; i<n; i++){
	   if(a[i].gia == giaDem) printf("Ten: %s - nam san xuat: %d - gia: %d\n", a[i].tenThietBi, a[i].namSanXuat, a[i].gia);	
	}
}

void ghiVaoTep(thietBi a[], int n){
	FILE *fp;
	fp = fopen("danhsachthietbi.txt", "w");
	for(int i=0; i<n; i++){
		fprintf(fp, "%s %d %d\n", a[i].tenThietBi, a[i].namSanXuat, a[i].gia);
	}
	fclose(fp);
}

void sapXepTheoNamBangDanhSach(thietBi a[], int n){
	FILE *fp;
	fp = fopen("danhsachthietbi.txt", "r");
	for(int i=0; i<n; i++){
		fscanf(fp, "%s %d %d\n", a[i].tenThietBi, a[i].namSanXuat, a[i].gia);
	}
//	fclose(fp);
	for(int i=0; i<n-1; i++){		
		thietBi nam = a[i];
		for(int j=i+1; j<n; j++){
			if(a[j].namSanXuat > nam.namSanXuat){
				thietBi temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			} 
		}		
	}
	fclose(fp);
}

int main(){
	thietBi *a;
	int n, giadem;
//	nhapThietBi(a, n);
//	xuatThietBi(a, n);
//	sapXepTheoGia(a, n);
//	xuatThietBi(a, n);
//    printf("\nLoc theo gia:"); scanf("%d", &giadem);
//    demThietBiTheoGia(a, n, giadem);
//    ghiVaoTep(a, n);
    sapXepTheoNamBangDanhSach(a, n);
    xuatThietBi(a, n);
}
