/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
%
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
	PhanSo operator +(const PhanSo& a) const;
	PhanSo operator -(const PhanSo& a) const;
	PhanSo operator *(const PhanSo& a) const;
	PhanSo operator /(const PhanSo& a) const;
	bool operator ==(const PhanSo& a) const;
	bool operator !=(const PhanSo& a) const;
	PhanSo operator -() const;
};

void PhanSo::Set(long t, long m){
    tu = t; 
    mau = m;
}

long gcd(long a, long b)
{
    // if (b == 0)
    //     return a;
    // else
    //     return gcd(b, a % b);
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
	return (tu == a.tu && mau == a.mau) ? true : false;
}

bool PhanSo::operator !=(const PhanSo& a) const{
	return (tu != a.tu && mau != a.mau) ? true : false;
}

PhanSo PhanSo::operator -() const{
	return PhanSo(-tu, mau);
}

int main() {
    string test;cin>>test;
	PhanSo a(4,6), b(-3,-4), c, d, e;
	cout << "a = "; a.Xuat(); cout << ", b = "; b.Xuat();cout<<endl;
	cout<<"PhanSo(2, -3) = ";PhanSo(2, -3).Xuat();cout<<endl;

	//Việc sử dụng các hàm để thực hiện các phép tính không được tự nhiên và tỏ ra dài dòng
	c = a.Cong(b);          cout << "a.Cong(b) = "; c.Xuat(); cout<<endl;
	//Viết đúng công thức toán học bằng cách định nghĩa chồng các toán tử
	d = a.operator + (b);   cout << "a.operator + (b) = "; d.Xuat(); cout<<endl; //Cách 1:dùng như hàm thông thường
	d = a + b;	            cout << "a + b = "; d.Xuat(); cout<<endl; //Cách 2: dùng như phép toán
	e = PhanSo(-2,-3) - a;  cout << "PhanSo(-2,-3) - a = "; e.Xuat(); cout<<endl;
	e = a * PhanSo(3,-2);   cout << "a * PhanSo(3,-2) = "; e.Xuat(); cout<<endl;
	e = PhanSo(3,-2) / PhanSo(-3,4);cout << "PhanSo(3,-2) / PhanSo(-3,4) = "; e.Xuat(); cout<<endl;

	cout << "c == d ?: " << boolalpha << (c == d) << "\n";
	cout << "c != d ?: " << boolalpha<<(c != d) << "\n";
	cout<<"-a = ";(-a).Xuat();cout<<endl;

	return 0;
}

