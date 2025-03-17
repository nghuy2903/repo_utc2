/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
#include <iostream>
#include <string.h>
using namespace std;

char *SaoChep(const char *s)
{
	return strcpy(new char[strlen(s) + 1], s);
}
class CONVAT
{
    protected:
        char *strTen;
        int iLoai; //0: cho,1:meo
    public:
        CONVAT ();
        CONVAT(char *ten);

//###INSERT CODE HERE -
        CONVAT(const CONVAT &other) ;
        virtual void XungTen() = 0; // Hàm thuần ảo hay được gọi là lớp trừu tượng
        static void InSoConNhap();
        CONVAT &operator =(const CONVAT &other);
        CONVAT* LayConVat(){return this;}
        int layLoai()const {return iLoai;}
        char* layTen()const {return strTen;}
        friend class DANHSACHCV;
        private:
            static int iSoConNhap; // Thuộc tính tĩnh dùng chung cho tất cả các lớp
};
//Hàm gọi thông qua lớp gọi là hàm phương thức tĩnh
int CONVAT::iSoConNhap = 0;
CONVAT::CONVAT(){
    strTen = nullptr;
}

CONVAT::CONVAT(char *ten){
    iSoConNhap++;
    strTen = SaoChep(ten);
    // iLoai = (strTen == "CHO") ?  1 : 0;
}

CONVAT::CONVAT(const CONVAT &other) {
    strTen = SaoChep(other.strTen);
    iLoai = other.iLoai;
    iSoConNhap++;
}

CONVAT &CONVAT::operator =(const CONVAT &other){
    // cout<<"\n(goi toan tu gan)";
    delete[] strTen;
    strTen = SaoChep(other.strTen);
    iLoai = other.iLoai;
    iSoConNhap++;
    
    return *this;
}


void CONVAT::InSoConNhap(){
    cout<<"\nSo con vat nhap kho: "<< iSoConNhap;
}

class CHO : public CONVAT{
    public:
        CHO() : CONVAT(){
            
            iLoai = 1;
        }
        CHO( char *ten) : CONVAT(ten){
            iSoChoNhap++;
            iLoai = 1;
        } 
        CHO(const CONVAT &other);
        CHO(const CHO &other);
        virtual void XungTen();
        static void InSoChoNhap(); 
        const CHO &operator =(const CHO &other);  

    private:
        static int iSoChoNhap;      
};

int CHO::iSoChoNhap = 0;

CHO::CHO(const CONVAT &other) : CONVAT(other){
    iSoChoNhap++;
    cout<<"\n(goi ham tao sao chep)";
}

CHO::CHO(const CHO &other){
    iSoChoNhap++;
    *this = other; 
}


const CHO &CHO::operator =(const CHO &other){
    CONVAT::operator=(other);
    iSoChoNhap++;
    return *this;
    // CONVAT *u1, *u2;
    // u1 = this->LayConVat();
    // u2 = other.LayConVat();

    // u1 = u2;
    // return other;

}

void CHO::XungTen(){
    cout<<"\nDay la con cho, ten la "<< strTen;
}

void CHO::InSoChoNhap(){
    cout<<"\nSo con cho nhap kho: "<<iSoChoNhap;
}


class MEO : public CONVAT{
    public:
        MEO() : CONVAT(){
            iLoai = 0;
        }
        MEO( char *ten) : CONVAT(ten){
            iSoMeoNhap++;
            iLoai = 0;
        } 
        MEO(const CONVAT &other);
        MEO(const  MEO &other);
        virtual void XungTen();      
        static void InSoMeoNhap();
        const MEO &operator =(const MEO &other);    
    private:
        static int iSoMeoNhap;
};

int MEO::iSoMeoNhap = 0; // Thuộc tính tĩnh chỉ được phép tạo 1 lần duy nhất ở bên ngoài lớp

MEO::MEO(const CONVAT &other) : CONVAT(other) {
    iSoMeoNhap++;
    cout<<"\n(goi ham tao sao chep)";
}

MEO::MEO(const MEO &other){
    iSoMeoNhap++;
    *this = other;
}

const MEO &MEO::operator =(const  MEO &other){
    CONVAT::operator=(other);
    iSoMeoNhap++;
    return *this;
    // CONVAT *u1, *u2;
    // u1 = this->LayConVat();
    // u2 = other.LayConVat();

    // u1 = u2;
    // return other;
}


void MEO::XungTen(){
    cout<<"\nDay la con meo, ten la "<< strTen;
}

void MEO::InSoMeoNhap(){
    cout<<"\nSo con meo nhap kho: "<< iSoMeoNhap;
}

class DANHSACHCV {
    private:
        CONVAT **ds; //ds là con trỏ cấp 2 quản lý 1 mảng con trỏ cấp 1
        int size,soCon, soCho, soMeo;    
    public:
        DANHSACHCV();
        DANHSACHCV(int s);
        ~DANHSACHCV();
        int Nhap(CONVAT *cv);
        void Nhap(int n);
        /*
        Lưu thông tin con vật
        Bổ sung vao chỗ trống
        Trả về vị trí vừa thêm
        */
        void In();
        void Ban(int x);
        void Ban(char* s);
        void Huy(int x);
};

DANHSACHCV::DANHSACHCV(){
    ds = nullptr;
    size = soCon = soCho = soMeo = 0;
}

DANHSACHCV::DANHSACHCV(int s) {
    soCho = soCon = soMeo = 0;
    size = s;
    ds = new CONVAT *[size];
    for (int i = 0; i < size; ++i) {
        ds[i] = nullptr; 
    }
}

DANHSACHCV::~DANHSACHCV() {
    for (int i = 0; i < size; ++i) {
        delete ds[i];
    }
    delete[] ds; 
}

int DANHSACHCV::Nhap(CONVAT* cv){
    bool check = false;
    for (int i = 0; i < size; ++i){
        if (ds[i] == nullptr){
            ds[i] = cv;
            soCon++;
            if(ds[i]->layLoai() == 1) soCho++;
            else if(ds[i]->layLoai() == 0) soMeo++;
            check = true;
            return i;
        }
    }
    if(!check){
        cout<<"\nHet cho, khong nhap duoc";
        return -1; 
    }
    
}

void DANHSACHCV::In(){
    cout << "\nDanh sach " << soCon << " cac con vat hien co, bao gom: " << soCho << " cho va " << soMeo << " meo";
    for(int i=0; i<size; i++){
        if(ds[i]!=nullptr){
            if(ds[i]->layLoai() == 1) cout << "\nCHO: " << ds[i]->layTen();
            else if(ds[i]->layLoai() == 0) cout << "\nMEO: " << ds[i]->layTen();
        }
    }
}

void DANHSACHCV::Huy(int x){
    
    if (ds[x] != nullptr) {
        soCon--;
        if (ds[x]->layLoai() == 1){
            cout << "\nDa ban con cho ten " << ds[x]->layTen();
            soCho--;
        }
        else if (ds[x]->layLoai() == 0){
            cout << "\nDa ban con meo ten " << ds[x]->layTen();
            soMeo--;
            
        }
        delete ds[x];
        ds[x] = nullptr;
    }
    cout<<"\n(goi ham huy giai phong vung nho)";
}

void DANHSACHCV::Ban(int x){
    if(x < 0 || x >= size) {
        cout<<"\nVi tri "<< x <<" khong hop le";
        return;
    }
    else if(ds[x] == nullptr) {
        cout<<"\nVi tri "<< x <<" chua co con vat nao";
        return;
    }
    else {
        Huy(x);
    }   
}

void DANHSACHCV::Ban(char* s){
    bool check = false;
    for(int i=0; i<size; i++){
        if(ds[i] != nullptr && strcmp(ds[i]->layTen(), s) == 0){
            
            Huy(i);
            check = true;
            return;
        }
    }
    if(!check) cout<<"\nKhong co con vat ten "<< s; 
}

void DANHSACHCV::Nhap(int n){
    
    bool k = soCon + n > size;
        if (soCon + n > size)
        {
            cout << "\nKhong du cho, ban co muon tiep tuc nhap khong?(c/k)";
            char c;
            cin >> c;
            if (c != 'c')
            {
                cout << "\nNhap khong thanh cong"; // 1 2 3
                return;
            }
        }
        do
        {
            int iloaimoi;
            char *ten;
            char tenMoi[100];
            do
            {
                cout << "\nNhap loai: ";
                cin >> iloaimoi;
                cout << "\nNhap ten: ";
                cin.ignore();
                cin.getline(tenMoi, sizeof(tenMoi));
                ten = SaoChep(tenMoi);
                if (iloaimoi != 1 && iloaimoi != 0)
                {
                    cout << "\nChua co loai nay, moi ban nhap lai";
                }
            } while (iloaimoi != 1 && iloaimoi != 0);
            CONVAT *convatmoi;
            if (iloaimoi == 0)
            {
                convatmoi = new CHO(ten);
            }
            else
            {
                convatmoi = new MEO(ten);
            }
            Nhap(convatmoi);
            convatmoi->XungTen();
            n--;
        } while (n > 0 && soCon != size);

        if (soCon == size && k)
        {
            cout << "\nHet cho, ket thuc viec nhap";
        }
        else
        {
            cout << "\nKet thuc viec nhap";
        }
}

int main()
{
    string s;cin>>s;
    CONVAT *c1 = new CHO("MUC"); CONVAT *c2 = new CHO("LAI"); CONVAT *c3 = new CHO("NHAT");
	c1->XungTen();c2->XungTen();c3->XungTen();
	CONVAT *m1 = new MEO("MUOP"); CONVAT *m2 = new MEO("DEN");
	m1->XungTen();m2->XungTen();




	DANHSACHCV d(7); //danh sách có tối đa 7 con
	d.Nhap(c1); d.Nhap(c2); int ic3 = d.Nhap(c3);
	d.Nhap(m1); d.Nhap(m2);
	d.In();


    d.Ban(ic3);
    d.In();
    d.Ban("DEN");
    d.In();
    d.Ban("MUN");

    d.Nhap(new CHO("HEO"));
    d.In();

    cout<<"\nNhap so con vat moi:";
    int n;cin>>n;
    d.Nhap(n);
    d.In();

	return 0;
}
