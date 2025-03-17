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
        virtual void XungTen() = 0; // Hàm thuần ảo hay được gọi là lớp trừu tượng
        static void InSoConNhap();
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

void CONVAT::InSoConNhap(){
    cout<<"\nSo con vat nhap kho: "<< iSoConNhap;
}
class CHO : public CONVAT{
    public:
        CHO() : CONVAT(){
            iLoai = 1;
        }
        CHO( char *ten) : CONVAT(ten){
            iLoai = 0;
        }  
        virtual void XungTen();
        static void InSoChoNhap();     
    private:
        static int iSoChoNhap;      
};
int CHO::iSoChoNhap = 0;
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
        virtual void XungTen();      
        static void InSoMeoNhap();
    private:
        static int iSoMeoNhap;
};

int MEO::iSoMeoNhap = 0; // Thuộc tính tĩnh chỉ được phép tạo 1 lần duy nhất ở bên ngoài lớp

void MEO::XungTen(){
    cout<<"\nDay la con meo, ten la "<< strTen;
}

void MEO::InSoMeoNhap(){
    cout<<"\nSo con meo nhap kho: "<< iSoMeoNhap;
}





int main()
{
    string test;cin>>test;

	CONVAT *c1 = new CHO("MUC"); CONVAT *c2 = new CHO("LAI"); CONVAT *c3 = new CHO("NHAT");
	c1->XungTen();c2->XungTen();c3->XungTen();
	CONVAT *m1 = new MEO("MUOP"); CONVAT *m2 = new MEO("DEN");
	m1->XungTen();m2->XungTen();
	CONVAT::InSoConNhap();
	MEO::InSoMeoNhap();
	CHO::InSoChoNhap();

	return 0;
}
