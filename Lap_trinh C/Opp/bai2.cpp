#include <iostream>
#include "string.h"
using namespace std;
char* saochep(char *s){
    return strcpy(new char[strlen(s) + 1], s );
}
class chuoi{
    char *p;
public:
    chuoi(char *s=""){p=saochep(s);}
    ~chuoi(){
        delete []p;
    }
    chuoi( const chuoi &s){p = saochep(s.p);}
    void nhap();
    void xuat();
    bool sosanh(chuoi s) const;
    chuoi get(){return p;}

};
void chuoi::nhap() {
    cin.getline(p,35);
}
void chuoi::xuat() {
    cout<<p<<" ";
}
bool chuoi::sosanh(chuoi s) const {
    if( strcmp( this->p, s.p) == 0){
        return 1;
    }
    return 0;
}
class NgayThang{
    int day, month, year;
public:
    void Input();
    void Output();
};
void NgayThang::Input(){
    cin>>day>>month>>year;
}
void NgayThang::Output(){
    cout<<day<<"/"<<month<<"/"<<year;
}
class NhanVien{
protected:
    int salary;
    int ms;
    double cccd;
    chuoi hoten;
    chuoi sex;
    NgayThang ngaysinh;
    chuoi diachi;
    chuoi sdt;
public:
    chuoi getten(){return hoten;}
    int getms(){return ms;}
    virtual   void  nhap() {
        // Thực hiện nhập thông tin cơ bản của nhân viên
        cin.ignore();
        cout << "Nhap ho ten: ";
        hoten.nhap();
        cout << "Nhap gioi tinh: ";
        sex.nhap();
        cout << "Address: ";
        diachi.nhap();
        cout << "Nhap SDT: ";
        sdt.nhap();
        cout << "CCCD: ";
        cin >> cccd;
        cout << "MSNV: ";
        cin >> ms;
        cout << "Ngay thang nam sinh: ";
        ngaysinh.Input();
    }
    virtual  void xuat(){
        cout<<"Ho va ten: ";
        hoten.xuat();
        cout<<"Gioi tinh: ";
        sex.xuat();
        cout<<"Dia chi: ";
        diachi.xuat();
        cout<<"SDT: ";
        sdt.xuat();
        cout<<"CCCD: ";
        cout<<cccd<<" ";
        cout<<"MSNV: ";
        cout<<ms<<" ";
        cout<<"Ngay thang nam sinh: ";
        ngaysinh.Output();
    }
};
class VanPhong: public  NhanVien{
private:
    int tglam;

public:
    void nhap()   override{
        NhanVien::nhap();
        cout << "Nhap TG da lam tai CT: ";
        cin >> tglam;
    }
    void xuat()  override{
        NhanVien::xuat();
        cout<<" TG da lam tai cong ty: ";
        cout<<tglam<<endl;
    }
    double tinhTienThuong() const {
        if (tglam < 6) {
            return 100000.0;
        } else {
            return 200000.0 + salary * 0.1 * (tglam / 6);
        }
    }
};
class BanHang: public  NhanVien{
private:
    int HesoThuong;
public:
    void nhap()   override{
        NhanVien::nhap();
        cout << "Nhap he so thuong rieng cua nhan vien: ";
        cin >> HesoThuong;
    }
    void xuat()  override{
        NhanVien::xuat();
        cout<<" He so thuong rieng: ";
        cout<<HesoThuong<<endl;
    }
  double tinhtienBanhang() const{
      return 150000.0 * HesoThuong;
    }

};

class SanXuat: public  NhanVien{
private:
    int SP;
public:
    void nhap()   override{
        NhanVien::nhap();
        cout << "Nhap so san pham da ban cua nhan vien: ";
        cin >> SP;
    }
    void xuat()  override{
        NhanVien::xuat();
        cout<<" So sp da ban: ";
        cout<<SP<<endl;
    }
double tinhtienSanxuat() const{
    return 20000.0 * SP;
    }
};
void nhapds(NhanVien *danhSachNhanVien[],int n){
    cin>>n;
    int luaChon;
    for(int i=0;i<n;i++) {
        cout<< "Chon loai nhan vien (1 - Nhan vien van phong, 2 - Nhan vien ban hang, 3 - Nhan vien san xuat, 0 - Ket thuc): ";
            cin >> luaChon;
            if (luaChon == 1) {
                VanPhong *vp = new VanPhong();
                vp->nhap();
                danhSachNhanVien[i] = vp;
            } else if (luaChon == 2) {
                BanHang *bh = new BanHang();
                bh->nhap();
                danhSachNhanVien[i] = bh;

            } else if (luaChon == 3) {
                SanXuat *sx = new SanXuat();
                sx->nhap();
                danhSachNhanVien[i] = sx;
            }
    }
}
void xuatds(NhanVien *danhSachNhanVien[],int n){
    for(int i=0;i<n;i++){
        danhSachNhanVien[i]->xuat();
    }
    for (int i = 0; i < n; i++) {
       delete danhSachNhanVien[i];
   }
}
void tim(NhanVien *danhSachNhanVien[],int n){
    chuoi p;
    cout << "Nhap ten nhan vien can tim:";
    cin.ignore();
    p.nhap();
    int found = 0;
    for (int i = 0; i < n; i++) {
        chuoi h = danhSachNhanVien[i]->getten();
        if (p.sosanh(h) == 1) {
            danhSachNhanVien[i]->xuat();
            found = 1;
            cout << endl;
            break;
        }
    }
    if (found == 0) {
        cout <<"No Found."<< endl;
    }
}

void sapxep(NhanVien *danhSachNhanVien[],int n){
    for (int i= 0; i<n; i++) {
        if(danhSachNhanVien[i]->getms() > danhSachNhanVien[i+1]->getms()){
            NhanVien *temp = danhSachNhanVien[i];
            danhSachNhanVien[i] = danhSachNhanVien[i + 1];
            danhSachNhanVien[i + 1] = temp;
        }
    }
}
void them(NhanVien *danhSachNhanVien[],int &n){
    cout<<"Them loai nhan vien nao?: ";
    string a;
    cin>>a;
    int z;
    cout<<"Them vao vi tri: ";
    cin>>z;
    for(int i = n; i > z; i--)
    {
        danhSachNhanVien[i] = danhSachNhanVien[i - 1];
    }
    if(a.compare("Van phong") ==0){
        VanPhong *vp = new VanPhong();
        vp->nhap();
        danhSachNhanVien[z] = vp;
    }
    else if( a.compare("Ban hang") == 0){
        BanHang *bh = new BanHang();
        bh->nhap();
        danhSachNhanVien[z] = bh;
    }
    else if( a.compare("San Xuat")==0){
        SanXuat *sx = new SanXuat();
        sx->nhap();
        danhSachNhanVien[z] = sx;
    }
    n++;
}
void xoa(NhanVien *danhSachNhanVien[],int &n){
    int z;
    cout<<"Xoa nhan vien co ma so: ";
    cin>>z;
    for(int i=0;i<n;i++){
        if( danhSachNhanVien[i]->getms() ==z ){
            z = i;
            break;
        }
    }
    for(int i = z; i < n; i++)
    {
        danhSachNhanVien[i] = danhSachNhanVien[i + 1];
    }
    n--;
}

int main() {
    int n;
    const int MAX_NHANVIEN = 100;
    NhanVien *danhSachNhanVien[MAX_NHANVIEN];
    int soLuongNhanVien = 0;
   nhapds(danhSachNhanVien,n);
   // tim(danhSachNhanVien,n);
   // sapxep(danhSachNhanVien,n);
  // xoa(danhSachNhanVien,n);
  //sua(danhSachNhanVien,n);
   xuatds(danhSachNhanVien,n);

}
