/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;

//###INSERT CODE HERE -

struct PS{
    int tu, mau;
};

void nhap(PS& a){
    cin >> a.tu >> a.mau;
}

int  Check(char c){
    if(c == '+') return 1;
     else if(c == '-') return 2;
      else if(c == '*') return 3;
       else return 4;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void cong(PS a, PS b){
     if(a.mau == 0 or b.mau == 0){
        cout << "Khong thoa yeu cau bai toan";
        return ;
    }
    int tu, mau;
    tu = a.tu * b.mau + b.tu *a.mau;
    mau = a.mau * b.mau; 
    int x =gcd(tu, mau);
    tu /= x;
    mau /= x;
    cout << tu << "/" << mau;
}

void nhan(PS a, PS b){
    if(a.mau == 0 or b.mau == 0){
        cout << "Khong thoa yeu cau bai toan";
        return ;
    }
    int tu, mau;
    tu = a.tu * b.tu;
    mau = a.mau * b.mau; 
    int x =gcd(tu, mau);
    tu /= x;
    mau /= x;
    cout << tu << "/" << mau;
}

void tru(PS a, PS b){
     if(a.mau == 0 or b.mau == 0){
        cout << "Khong thoa yeu cau bai toan";
        return ;
    }
    int tu, mau;
    tu = a.tu * b.mau - b.tu *a.mau;
    mau = a.mau * b.mau; 
    int x =gcd(tu, mau);
    tu /= x;
    mau /= x;
    cout << tu << "/" << mau;
}

void chia(PS a, PS b){
    int tu, mau;
    tu = a.tu * b.mau;
    mau = a.mau * b.tu; 

    if(mau == 0) {
        cout << "Phep chia khong xac dinh";
        return;
    }
    int x =gcd(tu, mau);
    tu /= x;
    mau /= x;
    cout << tu << "/" << mau;
}

int main()
{
    PS a, b;
    char c;

    nhap(a);
    nhap(b);
    cin >> c;
    
    int check = Check(c);

    if(check == 1) cong(a, b);
     else if(check == 2) tru(a, b);
      else if(check == 3) nhan(a, b);
       else chia(a, b);

    return 0;
}
