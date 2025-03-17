/**
 * Hà Văn Dũng
 * Nguyễn Nguyên Huy
*/

#include <bits/stdc++.h>
using namespace std;

class Diem {
private:
    int x, y;

public:
    Diem(int a = 0, int b = 0) {
        x = a, y = b;
    }
    int getX(){return x;};
    int getY(){return y;};
};

class DanhSachDiem {
private:
    int n;
    Diem *diem;
public:
    DanhSachDiem(int m = 0) {
        n = m;
        diem = new Diem[m];
    }
    ~DanhSachDiem() {
        n = 0;      
        delete[] diem;
    }
    void nhap();
    void xuat();
    void timKhoangCachNganNhat();
    void timDoiXung();
};

void DanhSachDiem::nhap() {
    cin >> n;
    *this = DanhSachDiem(++n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        diem[i] = Diem(x, y);
    }
}

void DanhSachDiem::xuat() {
    cout << "Danh sach diem trong mat phang Oxy:\n";
    for(int i = 0; i < n - 1; i++) {
        cout << "(" << diem[i].getX() << "," << diem[i].getY() <<  ")\n";
    }

    cout << "Nhap mot diem de kiem tra khoang cach:\n";
    timDoiXung();
    timKhoangCachNganNhat();
}

void DanhSachDiem::timDoiXung() {
    Diem diemXet = diem[n - 1];
    cout << "Diem doi xung voi (" << diemXet.getX() << "," << diemXet.getY() << ")" << " qua goc toa do O: (" << (-diemXet.getX()) << "," << (-diemXet.getY()) << ")\n";
}

void DanhSachDiem::timKhoangCachNganNhat() {
    Diem temp = diem[n-1];
    float m = sqrt(pow(-temp.getX() + diem[0].getX(), 2) + pow(-temp.getY() + diem[0].getY(), 2));
    Diem max = diem[0];
    for(int i = 1; i < n - 1; i++) {
        float res = sqrt(pow(-temp.getX() + diem[i].getX(), 2) + pow(-temp.getY() + diem[i].getY(), 2));
        if( res < m){
            m = res;
            max = diem[i];
            
        }
    }
    cout << "Diem co khoang cach ngan nhat toi (" << temp.getX() << "," << temp.getY() << "): (" << max.getX() << "," << max.getY() << ")\n";

}

int main()
{
    DanhSachDiem ds;
    ds.nhap();
    ds.xuat();
    return 0;
}
