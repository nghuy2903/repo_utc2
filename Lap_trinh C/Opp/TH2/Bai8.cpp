/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
#include <iostream>
#include <string.h>
#include <vector>
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
        int laySoLuongCon() const {return ds.size();}
        friend class DANHSACHCV;
        virtual void SinhCon(char* s) = 0;
        virtual void InCon() = 0;

        private:
            static int iSoConNhap; // Thuộc tính tĩnh dùng chung cho tất cả các lớp
            
        protected:
            vector<CONVAT*>ds;

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
            iLoai = 0;
        }
        CHO( char *ten) : CONVAT(ten){
            iSoChoNhap++;
            iLoai = 0;
        } 
        CHO(const CONVAT &other);
        CHO(const CHO &other);
        virtual void XungTen();
        static void InSoChoNhap();
        const CHO &operator =(const CHO &other);  
        virtual void SinhCon(char* s);
        virtual void InCon();
    private:
        static int iSoChoNhap;
        static int iSoChoCon;
};
int CHO::iSoChoCon = 0;

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

void CHO::SinhCon(char* s){
    iSoChoCon++;
    CHO* c = new CHO(s);
    ds.push_back(c);
}

void CHO::InCon(){
    cout << "\nDanh sach " << iSoChoCon << " con cua cho me " << layTen() << ", bao gom:"; 
    for (int i = 0; i < ds.size(); ++i) {
        cout << "\nCHO: " << ds[i]->layTen() << "(CHOCON)";
    }
    // cout  << strTen << " " << ds.size();

}

class MEO : public CONVAT{
    public:
        MEO() : CONVAT(){
            iLoai = 1;
        }
        MEO( char *ten) : CONVAT(ten){
            iSoMeoNhap++;
            iLoai = 1;
        } 
        MEO(const CONVAT &other);
        MEO(const  MEO &other);
        virtual void XungTen();      
        static void InSoMeoNhap();
        const MEO &operator =(const MEO &other); 
        virtual void SinhCon(char* s);
        virtual void InCon();   
    private:
        static int iSoMeoNhap;
        static int iSoMeoCon; 

};
int MEO::iSoMeoCon = 0;
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

void MEO::SinhCon(char* s){
    iSoMeoCon++;
    ds.push_back(new MEO(s));
}

void MEO::InCon(){
    cout << "\nDanh sach " << iSoMeoCon << " con cua meo me " << layTen() << ", bao gom:";
    for (int i = 0; i < ds.size(); ++i) {
        cout << "\nMEO: " << ds[i]->layTen() << "(MEOCON)";
    }

}

class DANHSACHCV {
    private:
        CONVAT **dscv; //ds là con trỏ cấp 2 quản lý 1 mảng con trỏ cấp 1
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
        CONVAT* timConVat(char* s);
};

DANHSACHCV::DANHSACHCV(){
    dscv = nullptr;
    size = soCon = soCho = soMeo = 0;
}

DANHSACHCV::DANHSACHCV(int s) {
    soCho = soCon = soMeo = 0;
    size = s;
    dscv = new CONVAT *[size];
    for (int i = 0; i < size; ++i) {
        dscv[i] = nullptr; 
    }
}

DANHSACHCV::~DANHSACHCV() {
    for (int i = 0; i < size; ++i) {
        delete dscv[i];
    }
    delete[] dscv; 
}

int DANHSACHCV::Nhap(CONVAT* cv){
    bool check = false;
    for (int i = 0; i < size; ++i){
        if (dscv[i] == nullptr){
            dscv[i] = cv;
            soCon++;
            if(dscv[i]->layLoai() == 0) soCho++;
            else if(dscv[i]->layLoai() == 1) soMeo++;
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
        if(dscv[i]!=nullptr){
            if(dscv[i]->layLoai() == 0) {
                cout << "\nCHO: " << dscv[i]->layTen();
                if(dscv[i]->laySoLuongCon() >=1) cout << " va " << dscv[i]->laySoLuongCon() << " con nho";
            }
            else if(dscv[i]->layLoai() == 1) {
                cout << "\nMEO: " << dscv[i]->layTen();
                if(dscv[i]->laySoLuongCon()>=1) cout << " va " << dscv[i]->laySoLuongCon() << " con nho";
            }
        }
        
    }
}

void DANHSACHCV::Huy(int x){
    
    if (dscv[x] != nullptr) {
        soCon--;
        if (dscv[x]->layLoai() == 0){
            cout << "\nDa ban con cho ten " << dscv[x]->layTen();
            soCho--;
        }
        else if (dscv[x]->layLoai() == 1){
            cout << "\nDa ban con meo ten " << dscv[x]->layTen();
            soMeo--;
            
        }
        delete dscv[x];
        dscv[x] = nullptr;
    }
    cout<<"\n(goi ham huy giai phong vung nho)";
}

void DANHSACHCV::Ban(int x){
    if(x < 0 || x >= size) {
        cout<<"\nVi tri "<< x <<" khong hop le";
        return;
    }
    else if(dscv[x] == nullptr) {
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
        if(dscv[i] != nullptr && strcmp(dscv[i]->layTen(), s) == 0){
            if(dscv[i]->laySoLuongCon() >=1 ){
                if(dscv[i]->layLoai() == 0) cout<<"\nKhong ban duoc do cho " << s << " phai nuoi " << dscv[i]->laySoLuongCon() << " con"; 
                else cout<<"\nKhong ban duoc do meo " << s << " phai nuoi " << dscv[i]->laySoLuongCon() << " con"; 
            }
            else {
               Huy(i);
                
            }   
            check = true; 
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


CONVAT* DANHSACHCV::timConVat(char* s){
    for(int i=0; i<size; i++){
        if(dscv[i] != nullptr && strcmp(dscv[i]->layTen(), s) == 0){
            return dscv[i];
        }
    }
    return nullptr;
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

    //Them chuc nang moi
    CONVAT* ic=d.timConVat("HEO");
    ic->SinhCon("heo1");
    ic->SinhCon("heo2");
    ic->SinhCon("heo3");
    ic->InCon();
    d.Ban("HEO");
    m1->SinhCon("muop1");
    m1->SinhCon("muop2");
    m1->InCon();
    d.Ban("MUOP");
    d.In();

	return 0;
}
