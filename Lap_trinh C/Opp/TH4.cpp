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
    void Set(long t = 0, long m = 1); //gán giá trị
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

int main() {
    string test;cin>>test;

	PhanSo a(2,3), b(4,1), c(0);
    PhanSo d = 5;		// tương đương PhanSo d = PhanSo(5);


    b = b + a + 5; 		// tương đương c = a + PhanSo(5);
    c = 3 + 1/(3-c); 		// tương đương c = PhanSo(3) + a
    a = 5+7;        //chuyển kiểu cả 2 toán hạng

    cout<<"a = ";a.Xuat(); cout<<endl;
	cout<<"b = ";b.Xuat(); cout<<endl;
	cout<<"c = ";c.Xuat(); cout<<endl;
	cout<<"d = ";d.Xuat(); cout<<endl;

	PhanSo x(2,3), y(1,4), z(3,1), t(2,5);

	x = y * -z;
	z = (y+2) * 2/x;
	t = x/3 + (y*z-2)/5;
	y=2*y-2;

	cout<<"x = ";x.Xuat(); cout<<endl;
	cout<<"y = ";y.Xuat(); cout<<endl;
	cout<<"z = ";z.Xuat(); cout<<endl;
	cout<<"t = ";t.Xuat(); cout<<endl;

	cout << "a >= -x ?: " << boolalpha<<(a >= -x) << "\n";
	cout << "c > (-1/y)*5 ?: " << boolalpha<<(c > (-1/y)*5) << "\n";
	cout << "d == -z - 1 ?: " << boolalpha<<(d == -z - 1) << "\n";
	cout << "t < t ?: " << boolalpha<<(t>t) << "\n";
	cout << "t <= t ?: " << boolalpha<<(t>=t) << "\n";
	
	return 0;
}
