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
        private:
            static int iSoConNhap; // Thuộc tính tĩnh dùng chung cho tất cả các lớp
};
//Hàm gọi thông qua lớp gọi là hàm phương thức tĩnh
int CONVAT::iSoConNhap = 0;
CONVAT::CONVAT(){
    strTen = nullptr;
}

CONVAT::CONVAT(char *ten){
    strTen = SaoChep(ten);
    // iLoai = (strTen == "CHO") ?  1 : 0;
}

CONVAT::CONVAT(const CONVAT &other) {
    strTen = SaoChep(other.strTen);
    iLoai = other.iLoai;
}

CONVAT &CONVAT::operator =(const CONVAT &other){
    // cout<<"\n(goi toan tu gan)";
    delete[] strTen;
    strTen = SaoChep(other.strTen);
    iLoai = other.iLoai;
    
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
    cout<<"\n(goi ham tao sao chep)";
}

CHO::CHO(const CHO &other){
    *this = other; 
}


const CHO &CHO::operator =(const CHO &other){
    CONVAT::operator=(other);
    
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
            iLoai = 1;
        }
        MEO( char *ten) : CONVAT(ten){
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
    cout<<"\n(goi ham tao sao chep)";
}

MEO::MEO(const MEO &other){
    *this = other;
}

const MEO &MEO::operator =(const  MEO &other){
    CONVAT::operator=(other);
    
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

int main()
{
    string s;cin>>s;

	CONVAT *c1 = new CHO("MUC"); CONVAT *c2 = new CHO("LAI"); CONVAT *c3 = new CHO("NHAT");
	CONVAT *m1 = new MEO("MUOP"); CONVAT *m2 = new MEO("DEN");

	MEO m3(*m1); m3.XungTen();
	CHO c4(*c3); c4.XungTen();

	MEO m4("HEO");
	MEO m5(m4);m5.XungTen();

	CHO c5("XIU");
	CHO c6(c5);c6.XungTen();

	return 0;
}
