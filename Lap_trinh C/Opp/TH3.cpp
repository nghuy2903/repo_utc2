/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
#include <iostream>
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

 void Xuat();
	PhanSo Cong(PhanSo a);
	friend PhanSo operator +(int a, const PhanSo& b);
	friend PhanSo operator -(int a, const PhanSo& b) ;
	friend PhanSo operator *(int a, const PhanSo& b);
	friend PhanSo operator /(int a ,const PhanSo& b);
    PhanSo operator +(const PhanSo& a) const;
	PhanSo operator -(const PhanSo& a) const;
	PhanSo operator *(const PhanSo& a) const;
	PhanSo operator /(const PhanSo& a) const;
	bool operator ==(const PhanSo& a) const;
	bool operator !=(const PhanSo& a) const;
	PhanSo operator -() const;

    PhanSo operator +(int a) const;
	PhanSo operator -(int a) const;
    PhanSo operator *(int a) const;
	PhanSo operator /(int a) const;

};

void PhanSo::Set(long t, long m){
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
	RutGon();
	if(tu*mau < 0) cout << "-";
	tu = abs(tu);
	mau = abs(mau);
	cout << tu;
	if(mau != 1) cout << "/" <<mau;
}

PhanSo PhanSo::Cong( PhanSo a){
	return PhanSo(a.tu * mau + tu *a.mau, a.mau * mau);
}

PhanSo operator +(int a, const PhanSo& b) {
	return PhanSo(a*b.mau + b.tu, b.mau);
}

PhanSo operator -(int a, const PhanSo& b) {
	return PhanSo(a*b.mau - b.tu, b.mau);
}

PhanSo operator *(int a, const PhanSo& b) {
	return PhanSo(a* b.tu, b.mau);
}

PhanSo operator /(int a, const PhanSo& b) {
	return PhanSo(a* b.mau, b.tu);
}

PhanSo PhanSo::operator -() const{
	return PhanSo(-tu, mau);
}

PhanSo PhanSo::operator +(int a) const{
	return PhanSo( tu + a*mau, mau);
}

PhanSo PhanSo::operator -(int a) const{
	return PhanSo( tu - a*mau, mau);
}

PhanSo PhanSo::operator *(int a) const{
	return PhanSo( tu * a, mau);
}

PhanSo PhanSo::operator /(int a) const{
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

int main() {
    string test;cin>>test;
	PhanSo x(2,3), y(1,4), z(3,1), t(2,5);

	x = y * -z;
	z = (y+2) * 2/x;
	t = x/3 + (y*z-2)/5;
	y=2*y-2;

	cout<<"x = ";x.Xuat(); cout<<endl;
	cout<<"y = ";y.Xuat(); cout<<endl;
	cout<<"z = ";z.Xuat(); cout<<endl;
	cout<<"t = ";t.Xuat(); cout<<endl;

	return 0;
}
