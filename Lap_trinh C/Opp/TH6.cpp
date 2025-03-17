/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
#include <iostream>
#include <math.h>
using namespace std;

class PhanSo
{	long tu, mau;
	void RutGon();
public:
    void Set(long t, long m); //gán giá trị
    PhanSo(){Set(0,1);};
	PhanSo(long t, long m) {Set(t,m);}

	long GetTu() const {return tu;}
	long GetMau() const {return mau;}






//###INSERT CODE HERE -
PhanSo(long t){Set(t, 1);}
	void Xuat();
	PhanSo Cong(PhanSo a);
	friend PhanSo operator +(long a, const PhanSo& b);
	friend PhanSo operator -(long a, const PhanSo& b) ;
	friend PhanSo operator *(long a, const PhanSo& b);
	friend PhanSo operator /(long a ,const PhanSo& b);

    PhanSo operator +(const PhanSo& a) const;
	PhanSo operator -(const PhanSo& a) const;
	PhanSo operator *(const PhanSo& a) const;
	PhanSo operator /(const PhanSo& a) const;

	bool operator ==(const PhanSo& a) const;
	bool operator !=(const PhanSo& a) const;
	bool operator >=(const PhanSo& a) const;
	bool operator >(const PhanSo& a) const;
	PhanSo operator -() const;

    PhanSo operator +(long a) const;
	PhanSo operator -(long a) const;
    PhanSo operator *(long a) const;
	PhanSo operator /(long a) const;

    operator float() const;


};

void PhanSo::Set(long t , long m){
    tu = t; 
    mau = m;
}

long gcd(long a, long b)
{
	a = abs(a);
	b = abs(b);
	if(a*b == 0) return a+b;
	if(a>b) return gcd(a-b, b);
	else return gcd(a, b-a);
}

void PhanSo::RutGon(){
    long x =gcd(tu, mau);
	if(mau != 0){
		tu /= x;
		mau /= x;
	}
	else cout << "loi\n";
}

void PhanSo::Xuat(){
	if (tu * mau < 0) cout << "-";
    long absTu = abs(tu);
    long absMau = abs(mau);
	long x =gcd(absTu, absMau);
	if(absMau != 0){
		absTu /= x;
		absMau /= x;
	}
	else cout << "loi\n";
    cout << absTu;
    if (absMau != 1) cout << "/" << absMau;
}

PhanSo PhanSo::Cong( PhanSo a){
	return PhanSo(a.tu * mau + tu *a.mau, a.mau * mau);
}

PhanSo operator +(long a, const PhanSo& b) {
	return PhanSo(a*b.mau + b.tu, b.mau);
}

PhanSo operator -(long a, const PhanSo& b) {
	return PhanSo(a*b.mau - b.tu, b.mau);
}

PhanSo operator *(long a, const PhanSo& b) {
	return PhanSo(a* b.tu, b.mau);
}

PhanSo operator /(long a, const PhanSo& b) {
	return PhanSo(a* b.mau, b.tu);
}

PhanSo PhanSo::operator +(long a) const{
	return PhanSo( tu + a*mau, mau);
}

PhanSo PhanSo::operator -(long a) const{
	return PhanSo( tu - a*mau, mau);
}

PhanSo PhanSo::operator *(long a) const{
	return PhanSo( tu * a, mau);
}

PhanSo PhanSo::operator /(long a) const{
	return PhanSo( tu , mau*a);
}

PhanSo PhanSo::operator +(const PhanSo& a) const{
	return PhanSo(a.tu * mau + tu *a.mau, a.mau * mau);
}

PhanSo PhanSo::operator -(const PhanSo& a) const{
	return PhanSo(tu *a.mau - a.tu * mau , a.mau * mau);
}

PhanSo PhanSo::operator *(const PhanSo& a) const{
	return PhanSo(tu * a.tu , a.mau * mau);
}

PhanSo PhanSo::operator /(const PhanSo& a) const{
	return PhanSo(tu * a.mau , a.tu * mau);
}

bool PhanSo::operator ==(const PhanSo& a) const{
	return (tu*a.mau == a.tu*mau);
}

bool PhanSo::operator !=(const PhanSo& a) const{
	return (tu != a.tu && mau != a.mau);
}

bool PhanSo::operator >=(const PhanSo& a) const{
	return (tu/mau >= a.tu/a.mau);
}

bool PhanSo::operator >(const PhanSo& a) const{
	return (tu*a.mau > a.tu*mau);
}

PhanSo PhanSo::operator -() const{
	return PhanSo(-tu, mau);
}

PhanSo::operator float() const{
    return float(tu)/float(mau);
}

int main(){
    string test; cin>>test;

    PhanSo a(2,3), b(3,4), c;
   cout << "sqrt(a)= "<<sqrt(a) << "\n"; 
    c = a + b;     cout<<"c = ";c.Xuat(); cout<<endl;      // Ok
    c = a + 2;     cout<<"c = ";c.Xuat(); cout<<endl;     // Nhap nhang: chuyển a thành số thực hay chuyển 2 thành phân số?
    c = 2 + a;     cout<<"c = ";c.Xuat(); cout<<endl;       // Nhap nhang
    double r = 2.5 + float(a); 
    cout << r << "\n";   // Nhap nhang
    r = float(a) + 2.5;  // Nhap nhang
    cout << r << endl;

    return 0;
}
